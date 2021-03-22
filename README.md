# 프로젝트명 : Docker Live Migration

## 1. Container 전체 옮기기
![image](https://user-images.githubusercontent.com/73922068/110815660-faa5ab80-82cd-11eb-8639-91cd1a5d0b96.png)
* 방법1. 공유폴더 생성

  - 가상머신1-노트북-가상머신2의 공유폴더 생성(/mnt/share=공유폴더)
  
    ![image](https://user-images.githubusercontent.com/73922068/110817195-650b1b80-82cf-11eb-81c0-9c2679b89eeb.png)
    
  - 가상머신1의 nginx 이미지 기반 container 실행(컨테이너 내부의 index.html 변경 후)
    
    $docker exec -it (container ID) /bin/bash : 도커 내부 접속
    
    $vim /usr/share/nginx/html index.html : index.html 변경
    
    결과 : 
    
    ![image](https://user-images.githubusercontent.com/73922068/110821122-1c556180-82d3-11eb-8359-03c1988b9d63.png)
    
  - 컨테이너->이미지로 변환
  
    $docker commit (컨테이너) (이미지이름):(태그)
    
  - 이미지->tar파일로 변환

    $docker save -o (tar파일이름) (이미지이름)
    
  - tar파일 공유폴더로 이동
  
    $docker mv (tar파일이름) /mnt/share
    
  - 가상머신2에서 공유폴더 조회
  
    $cd /mnt/share
    
    $ls
    
    결과 : 
    
    ![image](https://user-images.githubusercontent.com/73922068/110822195-29bf1b80-82d4-11eb-8b2c-867a4b4605c0.png)
    
  - tar파일->이미지로 변환
  
    $docker load -i (tar파일이름)
    
  - 해당 이미지로 컨테이너 실행
  
    결과 : 
    
    ![image](https://user-images.githubusercontent.com/73922068/110822663-9fc38280-82d4-11eb-884e-cc123b577466.png)
    
    ***
    
    
   
* Checkpoint
  - checkpoint create 부분에서 막힘..
  
    ![image](https://user-images.githubusercontent.com/73922068/111031890-200cf380-844d-11eb-88d5-3ad954cb3d62.png)
    
    checkpoint create 제한 : https://github.com/docker/cli/blob/master/experimental/checkpoint-restore.md

* 추가로 가능한 방법 조사
  - log파일
    
    /var/lib/docker/containers/<컨테이너id>/*.log 파일에서 ls,mkdir 등의 로그가 나오지 않음..
    
    docker exec 명령어로 해당 컨테이너 들어가서 디렉토리를 만들고 위의 경로로 들어가서 확인했을 때 해당 디렉토리가 없음-> 두 개가 서로 다른것
    인지??
    
    Dockerfile 작성법 : https://mino-park7.github.io/docker/2018/12/10/dockerfile/ 
    


