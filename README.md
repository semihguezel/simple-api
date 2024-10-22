# Simple API with CrowCpp
This project is a robust RESTful API application built using CrowCpp, a modern C++ microframework for web applications. The application provides endpoints to create and list notes, demonstrating fundamental CRUD operations in a lightweight and efficient manner.

## Project Components
### 1. CrowCpp
CrowCpp is a C++ microframework inspired by Python's Flask, designed for building fast and scalable web applications. It offers:

Routing: Simplified URL routing for handling HTTP requests.
Middleware Support: Ability to add middleware for processing requests and responses.
Concurrency: Built-in support for multithreading to handle multiple requests simultaneously.
### 2. Docker
Docker is utilized to containerize the application, ensuring consistency across different environments (development, testing, production). Key aspects include:

Dockerfile: Defines the environment and steps required to build the Docker image for the application.
Containerization: Packages the application and its dependencies into a single, portable container.

### 3. Docker Hub
Docker Hub serves as the container registry where the Docker image is stored and managed. Benefits include:

Image Hosting: Centralized storage for Docker images, facilitating easy distribution.
Versioning: Manage different versions of the Docker image through tagging.
Accessibility: Enables Kubernetes to pull the Docker image directly from Docker Hub.

### 4. Kubernetes
Kubernetes orchestrates the deployment, scaling, and management of containerized applications. This project leverages Kubernetes for:

Deployment Management: Ensures the desired state of the application is maintained.
Service Discovery: Manages internal and external access to the application via Services.
Scaling: Automatically adjusts the number of running instances based on demand.

### 5. Kubernetes Configuration Files
The Kubernetes configurations are modularized into two separate files for better organization:

simple-api-config.yaml

ConfigMap: Manages non-confidential configuration data such as environment variables.
Purpose: Decouples configuration from application code, allowing easy updates without rebuilding Docker images.
simple-api.config

Deployment: Defines the desired state for the application pods, including replicas, container images, and environment variables.
Service: Exposes the application to external traffic using a NodePort or LoadBalancer.
Purpose: Manages the deployment and networking aspects of the application.

### 6. Minikube
Minikube provides a local Kubernetes cluster for development and testing purposes. Advantages include:

Local Development: Allows developers to test Kubernetes deployments locally without the need for a cloud provider.
Ease of Use: Simplifies the process of running a Kubernetes cluster on a single machine.
Integration: Seamlessly integrates with Docker to build and deploy containerized applications within the local cluster.

### 7. ConfigMap
A ConfigMap is used to store configuration data in key-value pairs, which can be consumed by the application pods. Benefits include:

Flexibility: Easily update configuration settings without modifying application code.
Separation of Concerns: Keeps configuration separate from the container image, enhancing portability and maintainability.
Project Workflow
Development:

Write the application code using CrowCpp.
Define environment variables and configuration settings in simple-api-config.yaml.
Containerization:

Create a Dockerfile to build the Docker image.
Build the Docker image locally using Minikube's Docker daemon.
Push the Docker image to Docker Hub for accessibility.
Deployment:

Define Kubernetes Deployment and Service configurations in simple-api.config.
Apply the ConfigMap and Deployment configurations to the Kubernetes cluster using kubectl.
Expose the application externally via a Kubernetes Service.
Testing:

Use Minikube to run the Kubernetes cluster locally.
Access the application endpoints to verify functionality.
Update ConfigMaps and redeploy as needed without rebuilding Docker images.
Benefits of This Setup
Portability: Containerization ensures the application runs consistently across different environments.
Scalability: Kubernetes manages scaling the application seamlessly based on load.
Maintainability: Separation of configuration and code simplifies updates and maintenance.
Local Development: Minikube provides a convenient environment to develop and test Kubernetes deployments locally before deploying to a production cluster.


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
  
## 1. Install Minikube and kubectl

### Download kubectl
curl -LO "https://storage.googleapis.com/kubernetes-release/release/`curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt`/bin/linux/amd64/kubectl"

### Make it executable
chmod +x ./kubectl

### Move it to your PATH
sudo mv ./kubectl /usr/local/bin/kubectl

### Download Minikube
curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64

### Install Minikube
sudo install minikube-linux-amd64 /usr/local/bin/minikube

## 2. Build docker image
In your project repository run;
```bash
docker build -t simple_api:latest .
```
If you intend to deploy using the Kubernetes image, it has been pushed to Docker Hub. You can pull it using the following image tag: stonebrothers/simple_api:0.1.

## 3. Deploy to Kubernetes

### Start Minikube
minikube start --driver=docker

Apply the Kubernetes manifests, first we add configmap
```bash
kubectl apply -f simple-api-config.yaml
```
Then deployment & services
```bash
kubectl apply -f simple-api.yaml
```
## 4. Access the Application
Get the Minikube IP address
```bash 
minikube ip
```
Test the API:
```bash 
curl http://<returned_minikube_ip>:<nodePort>/hello

```
