# Console_game-avoid_object  
The consolegame of avoid falling object   
## 1. 개발 동기  
C++를 학습한 후 객체지향을 적용해 프로그래밍을 하기위해 시작하였다.  
|OS|사용 언어|사용 IDE|  
|:---:|:---:|:---:|  
|Windows10edu|C++ |Visual Studio 2019 |  
## 2. 파일    
* `Console.h`와 `Console.cpp`은 콘솔창을 다루기 편리하게 해주는 기본 헤더파일 이다. 
* 프로그램 실행시 버전에 따른 파일 한개와 위에 두 개의 파일을 포함해야 한다.  
* `main.cpp`는 이 프로젝트의 첫번째 버전이다. (Ver 1.0)  
* `Ver2.0`은 약간의 기능을 추가한 버전이며, 두번째 버전이다. (Ver 2.0)
## 3. 버전  
### 1 ) Ver 1.0  
>파일은 `main.cpp` 이며, 떨어지는 물체를 피하는 게임이다.  
> 용량때문에 실행결과를 자세히 첨부하지 못하였다.  
><p align="center"><img src="https://user-images.githubusercontent.com/77342519/125514955-98ad775d-6f23-4d9e-a87d-71fdf1c7448a.gif" width="500px"></p>  
><p align="center"> 실행결과 </p>  
><p align="center"><img src="https://user-images.githubusercontent.com/77342519/126398854-a161889a-82ef-4ec5-8161-2207a6b9c2e4.PNG" width="500px"></p>  
><p align="center"> 최종점수화면 </p>  

### 2 ) Ver 2.0  
>파일은 `Ver2.0` 이다.  
>  
>**< 업데이트 내용 >**
>* 화면창 확장(사이드)과 사이드에 정보 추가
>* Life기능(아래 영상 오른쪽 위 Life 참고) 도입과 Life추가 아이템 도입
>* score에 따른 난이도 조절, 난이도가 올라갈 때마다 random위치에서 Life를 추가하는 아이템 낙하
>
>**< 관련 영상 >**
><p align="center"><img src="https://user-images.githubusercontent.com/77342519/126400066-47587855-cf82-40fd-b248-f2843302a80b.gif" width="500px"></p>  
><p align="center"> 초반 낮은난이도에서 Life아이템 획득한 경우 Life가 상승하는 모습 </p>  
><p align="center"><img src="https://user-images.githubusercontent.com/77342519/126400078-53ebdefe-6bb8-4295-bee2-fe07b6a457ac.gif" width="500px"></p>  
><p align="center"> 난이도가 상승하고 물체와 충돌시 Life가 하나 감소하는 모습 </p>  
>
>**< Ver 2.0 Issue >**  
>실행 결과, score가 80이상이면 화면이 깜빡거리는 현상이 발견되었다.
  
### 3 ) Ver 2.1
> 준비중 . . .  
> * Ver 2.0 에서의 Issue 해결  
> * Pause 기능 도입  
> * 아이템 추가
