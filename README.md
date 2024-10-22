# Simple API with CrowCpp

This project is a simple RESTful API application using **CrowCpp**. The application allows you to create and list notes and is containerized using Docker.

## Features

- **`/hello`**: Returns a "Hello World!" message.
- **`/notes`**: Allows you to create and list notes.

## Requirements

- **C++14** or higher
- **CMake** (3.5 or higher)
- **Boost** library
- **Asio** or **Boost.Asio**
- **Docker** (optional, if you plan to use Docker)
- **Minikube** (optional, if you plan to use Docker)
- **Git** (optional)

## Deploying with Kubernetes and Minikube

### 1. Install Minikube and kubectl

## Download kubectl
curl -LO "https://storage.googleapis.com/kubernetes-release/release/`curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt`/bin/linux/amd64/kubectl"

## Make it executable
chmod +x ./kubectl

## Move it to your PATH
sudo mv ./kubectl /usr/local/bin/kubectl

## Download Minikube
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64

## Install Minikube
sudo install minikube-linux-amd64 /usr/local/bin/minikube

## Start Minikube
minikube start --driver=docker

### 2. Install Minikube and kubectl
```bash
docker build -t simple_api:latest .
```
If you intend to deploy using the Kubernetes image, it has been pushed to Docker Hub. You can pull it using the following image tag: stonebrothers/simple_api:0.1.

### 3. Deploy to Kubernetes
Apply the Kubernetes manifests, first we add configmap
```bash
kubectl apply -f simple-api-config.yaml
```
Then deployment & services
```bash
kubectl apply -f simple-api.yaml
```
### 4. Access the Application
Get the Minikube IP address
```bash 
minikube ip
```
Test the API:
```bash 
curl http://<returned_minikube_ip>:<nodePort>/hello

```
