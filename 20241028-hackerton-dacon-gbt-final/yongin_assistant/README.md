# Overview
see: [url](https://yb98.notion.site/2024-GBT-1c2cd80736dc808faac5debc39ec664b)

## Installation

```bash
sudo chmod 777 ./startup.sh
source ./startup.sh
```

## Deployment command
    
```bash
poetry lock --no-update 
docker build -t yongin-assistant:latest .
```