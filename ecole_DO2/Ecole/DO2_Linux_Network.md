## Part 1. ipcalc tool.

### 1.1 Networks and Masks

1.  192.160.0.0/13
    
    - 255.255.255.0 => /24 => 11111111.11111111.11111111.00000000
    - /15 => 255.254.0.0 => 11111111.11111110.00000000.00000000
    - 11111111.11111111.11111111.11110000 => 255.255.255.240 => /28
    
    - hostmin = 12.0.0.1 hostmax = 12.255.255.254
    - hostmin = 12.167.0.1 hostmax = 12.167.255.254
    - hostmin = 12.167.38.1 hostmax = 12.167.39.254
    - hostmin = 0.0.0.1 hostmax = 15.255.255.254
* * *
### 1.2 localhost

- 194.34.23.100 - no, not loopback
- 127.0.0.2 - yes, loopback
- 127.1.0.1 - yes, loopback
- 128.0.0.1 - no, not loopback

### 1.3 Network ranges and segments
* * *
1.  Private: 10.0.0.45, 192.168.4.2, 172.20.250.4, 172.16.255.255, 10.10.10.10;  
    Public: 134.43.0.2, 172.0.2.1, 192.172.0.1, 172.68.0.2, 192.169.168.1
2.  10.10.0.2, 10.10.10.10
* * *

## Part 2. Static routing between two machines

- ws1 ip -a output:  
    ![4fd7c80f402253bd772f0e1a2d0d1d51.png](../_resources/4fd7c80f402253bd772f0e1a2d0d1d51.png)
    
- ws2 ip -a output:  
    ![a929551e483b5591e397dbc4668b978a.png](../_resources/a929551e483b5591e397dbc4668b978a.png)
    
- network interface for internal network on both machines is 'enp1s0'
* * *
    
- ws1 etc/netplan/00-installer-config.yaml + netplan apply:  
    ![dff01b720af0236f950d0b1853e49f3c.png](../_resources/dff01b720af0236f950d0b1853e49f3c.png)  
    ![ca1b41967cb322dcc970795eede3d993.png](../_resources/ca1b41967cb322dcc970795eede3d993.png)  
* * *
- ws2 etc/netplan/00-installer-config.yaml + netplan apply:  
    ![a4e349476daa39157ae293eb47107ac4.png](../_resources/a4e349476daa39157ae293eb47107ac4.png)  
    ![4d0fb57842800aad4eb7826db4ca1eb8.png](../_resources/4d0fb57842800aad4eb7826db4ca1eb8.png)
* * *
### 2.1 Adding a static route manually:
- ip r add + ping outputs:
- ![5113d042f4add35bb224cf75cdbe8204.png](../_resources/5113d042f4add35bb224cf75cdbe8204.png)
* * *

### 2.2 Adding a static route with saving:
- /etc/netplan/00-installer-config.yaml and ping command outputs:
- ![901a29f4a7c0966665c1e0d4a66050c7.png](../_resources/901a29f4a7c0966665c1e0d4a66050c7.png)

## Part 3. iPerf3 utility

### 3.1 connection speed:
- 8 mbps = 1 MB/s
- 100 MB/s = 800000 Kbps
- 1 Gbps = 1073.742 Mbps
* * *

### 3.2 iPerf3 utility:
- connection speed between ws1 and ws2:
- ![b68e02802c4a3922f948d5dba8e3b2d8.png](../_resources/b68e02802c4a3922f948d5dba8e3b2d8.png)

## Part 4. Network firewall

### 4.1 iptables:
- etc/firewall.sh
- ![fb0caf3572ca40c7ca9a09c6d5c2f5a5.png](../_resources/fb0caf3572ca40c7ca9a09c6d5c2f5a5.png)
* * *
- running script
- ![0109da1c0fedd8cbb10fdc45d60857d8.png](../_resources/0109da1c0fedd8cbb10fdc45d60857d8.png)  
- *правила применяются сверху вниз до первого совпадения, поэтому в случае, когда первым идет deny, а после него allow - оно не переписывается, сохраняется только первое вхождение в table.*

### 4.2 nmap

- не пингуется, но host is up:
- ![b444e18ea0d43c2d3cc8ddd9cb228788.png](../_resources/b444e18ea0d43c2d3cc8ddd9cb228788.png)

## Part 5. Static network routing

**yaml конфиг у меня называется 50-cloud-init а не 00-installer-config, потому что образы Ubuntu 20.04 качал готовые для виртуальных машин, чтобы сэкономить время.*

### 5.1 Configuration of machine addresses

- r1:
- ![0acecaa0b91f07fa84ba2c84e067e070.png](../_resources/0acecaa0b91f07fa84ba2c84e067e070.png)
* * *
- r2:
- ![31a52f005df3d6e1330d7b3bd25166a1.png](../_resources/31a52f005df3d6e1330d7b3bd25166a1.png)
* * *
- ws11:
- ![c0187b2421fe87af521768b27cd7e154.png](../_resources/c0187b2421fe87af521768b27cd7e154.png)
* * *
- ws21:
- ![58b076e8cdcc02173eddd71ad04b97d5.png](../_resources/58b076e8cdcc02173eddd71ad04b97d5.png)
* * *
- ws22:
- ![875b12f4155609c6f9298cc648815dab.png](../_resources/875b12f4155609c6f9298cc648815dab.png)
* * *
- ping r1 from ws11 and ws22 from ws21:
- ![7b5780848d2728fe4e2ec87726e9ee42.png](../_resources/7b5780848d2728fe4e2ec87726e9ee42.png)

### 5.2 Enabling IP forwarding.

- sysctl -w
- ![e5e2a9ed688c677e6075d3970a066b85.png](../_resources/e5e2a9ed688c677e6075d3970a066b85.png)
- /etc/sysctl.conf
- ![0860b9023270f337ddf07189dac98e64.png](../_resources/0860b9023270f337ddf07189dac98e64.png)

### 5.3 default route

- ws11:
- ![c0187b2421fe87af521768b27cd7e154.png](../_resources/c0187b2421fe87af521768b27cd7e154.png)
- ![5ce62f0602037984aff74cb2d367ec74.png](../_resources/5ce62f0602037984aff74cb2d367ec74.png)
* * *
- ws21:
- ![58b076e8cdcc02173eddd71ad04b97d5.png](../_resources/58b076e8cdcc02173eddd71ad04b97d5.png)
- ![f169acfcac8be56ff856121619d1ceec.png](../_resources/f169acfcac8be56ff856121619d1ceec.png)
* * *
- ws22:
- ![875b12f4155609c6f9298cc648815dab.png](../_resources/875b12f4155609c6f9298cc648815dab.png)
- ![fa092c7f3a8d4b40b5cdd72692245e9c.png](../_resources/fa092c7f3a8d4b40b5cdd72692245e9c.png)
* * *
- ping from ws11 to r2:
- ![b944fce51894d6d606cf37f01793e900.png](../_resources/b944fce51894d6d606cf37f01793e900.png)

### 5.4 Adding static routes

- r1:
- ![0acecaa0b91f07fa84ba2c84e067e070.png](../_resources/0acecaa0b91f07fa84ba2c84e067e070.png)
- ![6bf0891a0ac1c813ca946ee175080267.png](../_resources/6bf0891a0ac1c813ca946ee175080267.png)
- r2:
- ![31a52f005df3d6e1330d7b3bd25166a1.png](../_resources/31a52f005df3d6e1330d7b3bd25166a1.png)
- ![618c49f5c9cfacd4996760c58231c440.png](../_resources/618c49f5c9cfacd4996760c58231c440.png)
- ip r list 10.10.0.0/\[netmask\] and ip r list 0.0.0.0/0 commands on ws11.
- ![3d7e418a06c651c4bcb6bca453bf87f6.png](../_resources/3d7e418a06c651c4bcb6bca453bf87f6.png)
- к адресу 0.0.0.0 (любому) по дефолту хост ws11 будет обращаться ЧЕРЕЗ роутер (10.10.0.1), то есть для внешнего мира пакеты идущие с хоста ws11 будут выглядеть как пакеты идущие с роутера 10.10.0.1.  
    в свою очередь правило для адреса 10.10.0.0/18 (локальная сеть) говорит о том, что внутри этой сети хост ws11 будет обращаться напрямую со своего адреса 'src 10.10.0.2'.
* * *

### 5.5 Making a router list

- Use traceroute utility to list routers in the path from ws11 to ws21 + Run the tcpdump -tnv -i eth0 dump command on r1
    
- ![f1da8165dfa4815f6da880e5acdb16bc.png](../_resources/f1da8165dfa4815f6da880e5acdb16bc.png)
    
- в общем ws11 посылает пакеты для ws21 через шлюз (r1) с увеличивающимся TTL. r1 по протоколу arp сообщает ws11 свой мак адрес; у шлюза r1 есть прописанный route до ws21 через r2 и он отправляет по нему пакеты от ws11. Как я понял, с каждого хоста на пути к ws22 (r1,r2) также отправляются пинги в обратную сторону на отправителя (ws11) с флагом time exceeded in transit, чтоб показать сколько времени шел пакет.   
* * *
### 5.6 Using ICMP protocol in routing:
- ws11: ping -c 1 10.30.0.111 command;  
    r1: tcpdump -n -i eth0 icmp command
- ![1deea9d102b206ab861c4b81623940bd.png](../_resources/1deea9d102b206ab861c4b81623940bd.png)

## Part 6. Dynamic IP configuration using DHCP

- r2 /etc/dhcp/dhcpd.conf & resolv.conf & systemctl restart isc-dhcp-server
- ![7c61371aca4e402f7bdb7d67c9d00964.png](../_resources/7c61371aca4e402f7bdb7d67c9d00964.png)
* * *
- ws21 reboot and ip a + ping ws22:
- ![95708a2f3a50252d783ddf33b871b785.png](../_resources/95708a2f3a50252d783ddf33b871b785.png)
- ![2d0410d90375e71387ef2e31df18fd10.png](../_resources/2d0410d90375e71387ef2e31df18fd10.png)
* * *
- ws11 netplan:
- ![bc753d0bd295cf4762a3f10001fb2761.png](../_resources/bc753d0bd295cf4762a3f10001fb2761.png)
- r1 dhcpd.conf & resolv.conf & systemctl restart isc-dhcp-server:
- ![a222bca34b905e2732edd0507597b5a7.png](../_resources/a222bca34b905e2732edd0507597b5a7.png)
* * *
- ws11 ip a + ping ws22:
- ![545c5e42852c5b5a62b56cce46cd779e.png](../_resources/545c5e42852c5b5a62b56cce46cd779e.png)
* * *
- запрос на обновление ip адреса с ws21:
- ![17a091027b43883c805b7390a3c5f7a5.png](../_resources/17a091027b43883c805b7390a3c5f7a5.png)
* * *
- *option routers 10.20.0.1 говорит клиенту что default gateway для него будет 10.20.0.1*
- *option domain-name-servers 10.20.0.1 - значит, что в качестве днс серверов (для выдачи доменных имен) для клиентов будет выступать R1 (или R2).*
- *так же на r1 использовал настройку под определенного хоста, с назначением айпи адреса вручную строго по мак адресу.*

## Part 7. NAT

- apache2 conf (*:80 = 0.0.0.0:80)
- ![c9296d05894a5e77e449c9c4a76cf5b0.png](../_resources/c9296d05894a5e77e449c9c4a76cf5b0.png)
- service apache2 start
- ![b24dd1d9af98a7c85cad5a09df1fb775.png](../_resources/b24dd1d9af98a7c85cad5a09df1fb775.png)
* * *
- r2 firewall.sh with FORWARD DROP policy:
- ![8eb7a8a3d6e70e93b9b60346224bf181.png](../_resources/8eb7a8a3d6e70e93b9b60346224bf181.png)
- ping ws22 from r1:
- ![21631c3f39911bf3c74ff5423e316b20.png](../_resources/21631c3f39911bf3c74ff5423e316b20.png)
* * *
- r2 firewall.sh with ACCEPT ICMP everywhere
- ![f0c7c03240534b8eecd8ad08026173e9.png](../_resources/f0c7c03240534b8eecd8ad08026173e9.png)
- ping ws22 from r1 now works:
- ![0d0dcf7effe0ccadfc645d851652d6ae.png](../_resources/0d0dcf7effe0ccadfc645d851652d6ae.png)
* * *
- SNAT MASQ all traffic coming from 10.20.0.0/26 and allow traffic to R1 apache:
- ![6792aa7c998785daa1e76a1d33ff32d4.png](../_resources/6792aa7c998785daa1e76a1d33ff32d4.png)
- access r1's apache server from ws22 with SNAT:
- ![fad784100463307acba6a49cef1d529a.png](../_resources/fad784100463307acba6a49cef1d529a.png)
	- tcpdump from r1 (видно что адрес r2):
	- ![a67b95458738218dcb34957ec71e525c.png](../_resources/a67b95458738218dcb34957ec71e525c.png)
* * *
- DNAT from R2 port 8080 to WS22 apache port 80:
- ![1629235b6f5c05b81b700b81166a3659.png](../_resources/1629235b6f5c05b81b700b81166a3659.png)
- access ws22's apache server from r1 using DNAT through r2:
- ![b0070b5975a5df9bb66734863fb4a0dd.png](../_resources/b0070b5975a5df9bb66734863fb4a0dd.png)

## Part 8. Bonus. Introduction to SSH Tunnels
- Редактируем конфигурацию апаче ws22, чтобы он слушал только на локалхосте и перезагружаем сервис:
- ![fb356ef9be1d2b3deea27f69a018ffb8.png](../_resources/fb356ef9be1d2b3deea27f69a018ffb8.png)
* * *
### 1. Local tcp forwarding:
- SSH tunnel from port 42069 on ws21 to port 80 on ws22:
- `user@ws21:~$ ssh -L <локальный_порт>:127.0.0.1:<внешний_порт_апачe> user@ws22`
![e3c31799e4ed49a15be5239b3eb13223.png](../_resources/e3c31799e4ed49a15be5239b3eb13223.png)
* * *
- видим что есть доступ к apache на ws22 с локального порта 42069 на ws21:
![7f1e86e5d1db6dda6ca64dff86deecae.png](../_resources/7f1e86e5d1db6dda6ca64dff86deecae.png)
* * *
### 2. Remote tcp forwarding:
- в фаерволе на r2 разрешаем SSH Forwarding (port 22) для ws11:
- ![037710be195dcd92e1f8883694f934ca.png](../_resources/037710be195dcd92e1f8883694f934ca.png)
* * *
- SSH tunnel from port 80 on ws22 to port 12345 on ws11:
- `user@ws22:~$ ssh -R <внешний_порт>:127.0.0.1:<локальный_порт_апачe> user@ws11`
- ![3e7a29ca129dfb53c79e1e281f71d719.png](../_resources/3e7a29ca129dfb53c79e1e281f71d719.png)
* * *
- видим, что есть доступ к apache на ws22 с локального порта 12345 ws11:
- ![7aae2dfe1665f85cbcdaf06310b00c5d.png](../_resources/7aae2dfe1665f85cbcdaf06310b00c5d.png)
 