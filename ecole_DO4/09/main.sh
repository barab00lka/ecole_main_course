#!/usr/bin/env bash

# Запускаем nginx веб сервер на 9101 порту локалхост и запускаем скрипт custom_node_exporter. Страница с метриками будет обновляться каждые 5 секунд. Затем добавляем метрики в prometheus.

mkdir -p ./nginx/html
# Создаем компоуз для нгинха
cat << EOF > ./docker-compose.yml
---
version: "3.3"

networks:
  07_metrics_network:
    external: true

services:
  custom_node_my:
    image: nginx:latest
    container_name: custom_node_my
    networks:
      07_metrics_network:
    ports:
      - "9101:80"
    restart: always
    volumes:
      - ./nginx/html:/usr/share/nginx/html
EOF

# Добавляем в конфиг prometheus кастомный node_exporter
cat << EOF >> ../07/prometheus/prometheus.yml

  - job_name: 'custom_node'
    static_configs:
      - targets:
          - 'custom_node_my:80'
    metrics_path: /metrics.txt
EOF

# Запускаем скрипт эксопортёра в фоне
# Вспомогательный скрипт должен лежать ТАМ ЖЕ, где находится этот скрипт (основной).
DIR="$(dirname "$0")"
chmod +x "$DIR/custom_node_exporter.sh"
"$DIR/custom_node_exporter.sh" &

# Заводим сервер нгинкс на котором будут выводиться метрики и перезагружаем все остальные сервисы
sudo docker-compose up -d && sudo docker restart prometheus grafana

echo "Можно посмотреть веб страницу с метриками по адресу http://localhost:9101/metrics.txt/"
