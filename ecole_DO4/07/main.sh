#!/usr/bin/env bash

# установка докера
sudo apt update && sudo apt install docker docker-compose stress

# установка и конфигурация Prometheus и Grafana в Docker
mkdir -p ./prometheus

cat << EOF > ./docker-compose.yml
---
version: "3.3"

networks:
  metrics_network:
    driver: bridge
    ipam:
      config:
        - subnet: 192.168.21.0/24

services:
  prometheus:
    image: prom/prometheus:latest
    networks:
      metrics_network:
    ports:
      - '9090:9090'
    container_name: prometheus
    volumes:
      - ./prometheus:/etc/prometheus/
    command:
      - --config.file=/etc/prometheus/prometheus.yml
    restart: unless-stopped

  grafana:
    user: root
    image: grafana/grafana
    container_name: grafana
    depends_on:
      - prometheus
    ports:
      - '3000:3000'
    networks:
      metrics_network:
    volumes:
      - ./grafana:/var/lib/grafana
      - ./grafana/provisioning:/etc/grafana/provisioning/
    restart: unless-stopped

  node_exporter:
    image: prom/node-exporter
    networks:
      metrics_network:
    ports:
      - '9100:9100'
    container_name: node_exporter
    restart: unless-stopped
    volumes:
      - /:/rootfs:ro,rslave
      - /proc:/host/proc:ro
      - /sys:/host/sys:ro
    command:
      - --path.procfs=/host/proc
      - --path.sysfs=/host/sys
      - --collector.filesystem.ignored-mount-points
      - ^/(sys|proc|dev|host|etc|rootfs/var/lib/docker/containers|rootfs/var/lib/docker/overlay2|rootfs/run/docker/netns|rootfs/var/lib/docker/aufs)($$|/)
EOF

cat << EOF > ./prometheus/node_rules.yaml
"groups":
- "name": "node-exporter.rules"
  "rules":
  - "expr": |
      count without (cpu) (
        count without (mode) (
          node_cpu_seconds_total{job="node"}
        )
      )
    "record": "instance:node_num_cpu:sum"
  - "expr": |
      1 - avg without (cpu, mode) (
        rate(node_cpu_seconds_total{job="node", mode="idle"}[1m])
      )
    "record": "instance:node_cpu_utilisation:rate1m"
  - "expr": |
      (
        node_load1{job="node"}
      /
        instance:node_num_cpu:sum{job="node"}
      )
    "record": "instance:node_load1_per_cpu:ratio"
  - "expr": |
      1 - (
        node_memory_MemAvailable_bytes{job="node"}
      /
        node_memory_MemTotal_bytes{job="node"}
      )
    "record": "instance:node_memory_utilisation:ratio"
  - "expr": |
      rate(node_vmstat_pgmajfault{job="node"}[1m])
    "record": "instance:node_vmstat_pgmajfault:rate1m"
  - "expr": |
      rate(node_disk_io_time_seconds_total{job="node", device!=""}[1m])
    "record": "instance_device:node_disk_io_time_seconds:rate1m"
  - "expr": |
      rate(node_disk_io_time_weighted_seconds_total{job="node", device!=""}[1m])
    "record": "instance_device:node_disk_io_time_weighted_seconds:rate1m"
  - "expr": |
      sum without (device) (
        rate(node_network_receive_bytes_total{job="node", device!="lo"}[1m])
      )
    "record": "instance:node_network_receive_bytes_excluding_lo:rate1m"
  - "expr": |
      sum without (device) (
        rate(node_network_transmit_bytes_total{job="node", device!="lo"}[1m])
      )
    "record": "instance:node_network_transmit_bytes_excluding_lo:rate1m"
  - "expr": |
      sum without (device) (
        rate(node_network_receive_drop_total{job="node", device!="lo"}[1m])
      )
    "record": "instance:node_network_receive_drop_excluding_lo:rate1m"
  - "expr": |
      sum without (device) (
        rate(node_network_transmit_drop_total{job="node", device!="lo"}[1m])
      )
    "record": "instance:node_network_transmit_drop_excluding_lo:rate1m"
EOF

cat << EOF > ./prometheus/prometheus.yml
global:
  scrape_interval: 5s
  evaluation_interval: 5s

rule_files:
  - "node_rules.yaml"

scrape_configs:
  - job_name: 'node'
    static_configs:
      - targets:
          - 'node_exporter:9100'
EOF

sudo docker-compose up -d

echo""
echo "Grafana dashboard is available at http://localhost:3000/"
echo ""
echo "Login: admin"
echo "Password: admin"
echo ""
echo "You can import dashboards by ID from Grafana labs website."
echo "Linux Hosts Metrics | Base: ID - 10180"
echo "Node exporter simple: ID - 10372"
