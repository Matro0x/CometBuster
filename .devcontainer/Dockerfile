# Étape 1 : image de base
FROM mcr.microsoft.com/devcontainers/base:noble

# Étape 2 : mettre à jour et installer des paquets système
RUN apt update && apt-get install -y \
    curl \
    git \
    libsdl1.2-dev \
    libsdl-ttf2.0-dev \
 && apt-get clean && rm -rf /var/lib/apt/lists/*

# Étape 3 : définir le répertoire de travail
WORKDIR /workspace

