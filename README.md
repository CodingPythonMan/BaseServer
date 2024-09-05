# BaseServer
## Goal
C++ 로 만드는 간단한 채팅 서버. Minidump 랑 DB까지만 적용시켜보자.

## Status
서버는 이렇게도 만들어보고 저렇게도 만들어봐야한다. 하지만, 그랬을 때 제일 중요한 점은 해당 서버를 테스트한 결과일 것이다.<br>
테스트를 반드시 마치는 쪽으로 간다.

## Manual
- NetworkJob : 직렬화 버퍼
- NetworkService : 연결 전 세션 처리
- ServerService : 연결 후 Send 및 Recv 처리