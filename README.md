# EpicSeven-SpeedGearCalc

> 게임 **에픽세븐**의 속도 템 강화시 최종 속도 확률을 계산하는 프로그램입니다.<br>
> 공식 강화 확률: [에픽세븐 공지 링크](https://page.onstove.com/epicseven/kr/view/7902451)


## 소개

- 작성 언어: C
- 전설/영웅 장비 강화 및 제련 시 속도 증가량의 확률 분포를 계산합니다.

---

## 기능

- 전설/영웅의 장비 등급 선택 가능
- 초기 속도값 입력과 이를 기반으로 최종 속도 분포 계산
- 확률은 소숫점 셋째 자리까지 출력

## 빌드방법

```bash
gcc -o epic7speedcalc src/main.c src/calc.c src/utils.c -lm