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
    
    #1. docker logs <컨테이너id>
    
    ![image](https://user-images.githubusercontent.com/73922068/112845565-f22bde00-90df-11eb-9dac-11bbfa6cbf84.png)

    -> 이미지는 만들어지나, 컨테이너를 생성해보면 script.sh 파일에 아무내용도 적혀있지 않음.
    
    -> cut 할 때 맨처음 명령어는 안나오는 이유는 log의 첫번째 명령어는 #이 두개임
    
    ![image](https://user-images.githubusercontent.com/73922068/112850429-f27aa800-90e4-11eb-88c8-858fc65def16.png)

    
    #2. 외부에서 만든 script.sh 파일을 Dockerfile로 COPY
    
    ![image](https://user-images.githubusercontent.com/73922068/112845679-1687ba80-90e0-11eb-939b-a05a92a58622.png)
    
    -> 이미지 생성 안됨. 대신 컨테이너가 바로 생성됨. 컨테이너는 restart 해도 바로 꺼져버림.
    
    #2. <컨테이너id>-json.log 파일을 파싱하는 방법
    
    -> log파일을 파싱하려했지만 mkdir\r\s 의 \r을 cut명령어로 제거하는 방법을 모르겠음..
    

