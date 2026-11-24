#!/usr/bin/env bash
set -euo pipefail
LC_TIME=C
# gen_nginx_logs.sh
# Генерирует 5 nginx access логов в combined формате.
# Каждый лог соответствует одному дню; в каждом логе случайное количество
# записей от 100 до 1000; timestamps внутри дня в возрастающем порядке.
#
# Комментарии (на русском) — что означают коды ответов, используемые в скрипте:
# 200 OK        — Запрос успешно обработан (стандартный успех)
# 201 Created   — Ресурс успешно создан (обычно ответ на POST)
# 400 Bad Request — Неправильный запрос от клиента (синтаксическая ошибка)
# 401 Unauthorized — Неавторизованный (требуется аутентификация)
# 403 Forbidden  — Доступ запрещён (сервер понял, но отказывает)
# 404 Not Found  — Ресурс не найден
# 500 Internal Server Error — Внутренняя ошибка сервера
# 501 Not Implemented — Функция не реализована на сервере
# 502 Bad Gateway — Плохой ответ от верхнего (upstream) сервера
# 503 Service Unavailable — Сервис временно недоступен (перегрузка/обслуживание)
#

TZ="Europe/Amsterdam"  # часовой пояс для меток в логах
DAYS=5                 # количество лог-файлов (по одному на день)
MIN_LINES=100
MAX_LINES=1000

CODES=(200 201 400 401 403 404 500 501 502 503)
METHODS=(GET POST PUT PATCH DELETE)
URLS=(
  "/"
  "/index.html"
  "/about"
  "/contact"
  "/products"
  "/products/%d"
  "/api/v1/users/%d"
  "/api/v1/login"
  "/search?q=%s"
  "/assets/css/style.css"
  "/assets/js/app.js"
)
#REFERERS=(
#  "platform.21-school.ru"
#  "dojki.com"
#  "example.com/"
#  "google.com/"
#  "yandex.ru/"
#  "example.org/page"
#)

UAS=(
  "Mozilla/5.0 (Windows NT 10.0; Win64; x64) Gecko/20100101 Firefox/117.0"   # Mozilla
  "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0" # Chrome
  "Opera/9.80 (Windows NT 6.1; WOW64) Presto/2.12.388 Version/12.18"        # Opera
  "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/16.0 Safari/605.1.15" # Safari
  "Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.1; Trident/6.0)"        # IE
  "Mozilla/5.0 (Windows NT 10.0; Win64; x64) Edge/18.19041" # Edge
  "Googlebot/2.1 (+http://www.google.com/bot.html)"                        # crawler/bot
  "curl/7.81.0"                                                            # library/net tool
)

rand_between() {
  local min=$1 max=$2
  echo $(( RANDOM % (max - min + 1) + min ))
}

random_ip() {
  # Генерация корректного IPv4 (каждый октет 1..254)
  echo "$((RANDOM%254+1)).$((RANDOM%254+1)).$((RANDOM%254+1)).$((RANDOM%254+1))"
}

random_choice() {
  local arrname=$1
  local -n arr=$arrname
  echo "${arr[RANDOM % ${#arr[@]}]}"
}

for ((day_idx=0; day_idx < DAYS; day_idx++)); do
  daydate=$(date -d "today - $day_idx days" +%F)  # YYYY-MM-DD
  logfile="access-$daydate.log"
  echo "Generating $logfile ..."

  lines=$((RANDOM % (MAX_LINES - MIN_LINES + 1) + MIN_LINES))

  tmpfile=$(mktemp)
  # Удалим tmp при выходе (на случай прерывания)
  trap 'rm -f "$tmpfile"' EXIT

  for ((i=0; i<lines; i++)); do
    # случайная секунда в дне
    sec=$(((RANDOM * RANDOM) % 86400))
    echo "$sec" >> "$tmpfile"
  done

  mapfile -t secs < <(sort -n "$tmpfile")
  rm -f "$tmpfile"
  trap - EXIT

  : > "$logfile"

  for sec in "${secs[@]}"; do
    ip=$(random_ip)
    code=${CODES[RANDOM % ${#CODES[@]}]}
    method=${METHODS[RANDOM % ${#METHODS[@]}]}

    url_template=$(random_choice URLS)
    if [[ "$url_template" == *"%d"* ]]; then
      id=$((RANDOM % 9999 + 1))
      url=$(printf "$url_template" "$id")
    elif [[ "$url_template" == *"%s"* ]]; then
      terms=(apple banana test query nginx log sample user)
      term="${terms[RANDOM % ${#terms[@]}]}"
      url=$(printf "$url_template" "$term")
    else
      url="$url_template"
    fi

    #bytes=$(( (RANDOM % 5000) + 200 ))
    #referer=$(random_choice REFERERS)
    ua=$(random_choice UAS)

    timestamp=$(TZ="$TZ" date -d "$daydate UTC +$sec seconds" +"%d/%b/%Y:%H:%M:%S %z")

    printf '%s - [%s] "%s %s HTTP/1.1" %s - "-" "%s"\n' \
      "$ip" "$timestamp" "$method" "$url" "$code" "$ua" >> "$logfile"
  done

  echo "Wrote $lines entries to $logfile"
done

echo "Done. Generated $DAYS log files."

