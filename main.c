#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


typedef struct object {
	int object_Money; //물품 가격
	int object_Number; //물품 번호
	char object_Name[100]; //물품 이름
} object;

typedef struct user {
	int user_Money; //참여자 소지금액
	int user_Number; //참여자 번호
	int user_object_number; //참여자 소지물품 갯수
	char user_Name[100]; //참여자 이름
	object* user_Object; //참여자 소지물품 (포인터)
} user;

int main() {
	int choice = 0;
	int skip = 0; //설명 스킵
	int people_Number = 0; //참여인원 수
	int object_Number = 0; //물품 수
	int first_money = 10000; //초기 자금 기본설정 만원
	int bid_time = 15; //입찰 시간 기본설정 15초
	user* users; //포인터
	users = NULL; //NULL로 초기화
	object* objects = (object*)malloc(object_Number * sizeof(object)); //포인터 및 동적할당 (0칸(NULL))
	while (1) {
		printf("현재 설정\n");
		printf("==================================\n\n");
		printf("인원 목록\n");
		printf("----------------------------------\n");
		if (people_Number == 0) { printf("설정된 인원이 없습니다.\n"); } //예외처리
		else { for (int i = 0; i < people_Number; i++) { printf("%d. %s\n", i + 1, users[i].user_Name); } } //참여자 목록
		printf("==================================\n\n");
		printf("물품 목록\n");
		printf("----------------------------------\n");
		if (object_Number == 0) { printf("설정된 물품이 없습니다.\n"); } //예외처리
		else { for (int i = 0; i < object_Number; i++) { printf("%d. %s>>%d원\n", i + 1, objects[i].object_Name, objects[i].object_Money); } } //물품 목록
		printf("==================================\n");
		printf("초기 자금: %d원\n", first_money);
		printf("입찰 시간: %d초\n", bid_time);
		if (skip == 0) { printf("설명 건너뛰기: 비활성화\n"); }
		else { printf("설명 건너뛰기: 활성화\n"); }
		printf("==================================\n\n"); //현재 설정

		printf("==================================\n");
		printf("1. 경매 설정\n");
		printf("2. 경매 시작\n");
		printf("3. 경매 초기화\n");
		printf("4. 종료\n");
		printf("==================================\n");
		printf("메뉴 번호>>");
		scanf_s("%d", &choice);
		system("cls");
		if (choice == 1) { //경매 설정
			printf("==================================\n");
			printf("1. 경매물품 설정\n");
			printf("2. 경매물품 수정\n");
			printf("3. 경매인원 설정\n");
			printf("4. 기타 설정\n");
			printf("5. 뒤로가기\n");
			printf("==================================\n");
			printf("메뉴 번호>>");
			scanf_s("%d", &choice);
			if (choice == 1) { //경매물품 설정
				if (object_Number != 0) { //오류 방지
					printf("이미 설정되있습니다.\n");
					continue;
				}
				printf("==================================\n");
				printf("총 물품 수를 적어주세요>>");
				scanf_s("%d", &object_Number);
				objects = (object*)realloc(objects, object_Number * sizeof(object)); //동적메모리 재할당
				for (int i = 0; i < object_Number; i++) {
					printf("==================================\n");
					printf("%d번째 물품 이름을 적어주세요>>", i + 1);
					scanf("%s", &objects[i].object_Name);
					printf("%d번째 물품 가격을 적어주세요>>", i + 1);
					scanf_s("%d", &objects[i].object_Money);
					objects[i].object_Number = (i + 1);
				}
				system("cls");
			}
			else if (choice == 2) { //경매 물품 수정
				system("cls");
				printf("==================================\n");
				printf("1. 경매물품 교체\n");
				printf("2. 경매물품 추가\n");
				printf("3. 뒤로가기\n");
				printf("==================================\n");
				printf("메뉴 번호>>");
				scanf_s("%d", &choice);
				char replace_object[100];
				if (choice == 1) { //경매 물품 교체
					if (object_Number == 0) { //오류방지
						printf("==================================\n");
						printf("설정된 물품이 없습니다.\n");
						break;
					}
					printf("==================================\n");
					printf("교체하고 싶은 물품 이름>>");
					scanf("%s", &replace_object);
					for (int i = 0; i < object_Number; i++) { //물품 이름 인식
						if (strcmp(objects[i].object_Name, replace_object) == 0) {
							printf("수정하고 싶은 이름을 적어주세요>>");
							scanf("%s", &objects[i].object_Name);
							printf("%s의 가격을 적어주세요>>", objects[i].object_Name);
							scanf_s("%d", &objects[i].object_Money);
							continue;
						}
					}
					system("cls");
				}
				else if (choice == 2) { //경매 물품 추가
					int add_object_Number = 0;
					if (object_Number == 0) { //오류방지
						printf("==================================\n");
						printf("설정된 물품이 없습니다.\n");
						break;
					}
					printf("==================================\n");
					printf("추가하고 싶은 총 물품 수를 적어주세요>>");
					scanf_s("%d", &add_object_Number);
					objects = (object*)realloc(objects, (object_Number + add_object_Number) * sizeof(object)); //동적메모리 재할당
					for (int i = 0; i < add_object_Number; i++) {
						printf("==================================\n");
						printf("%d번째 물품 이름을 적어주세요>>", i + 1);
						scanf("%s", &objects[object_Number + i].object_Name);
						printf("%d번째 물품 가격을 적어주세요>>", i + 1);
						scanf_s("%d", &objects[object_Number + i].object_Money);
						objects[object_Number + i].object_Number = (object_Number + i + 1);
					}
					object_Number += add_object_Number; //총 물품 갯수
					system("cls");
				}
				else if (choice == 3) { system("cls"); continue; } //뒤로가기
				else { //오류방지
					printf("==================================\n");
					printf("정확한 숫자로 입력해주세요.\n");
					continue;
				}
				
			}
			else if (choice == 3) { //경매인원 설정
				if (users != NULL) { //만약 인원 재설정시 동적할당 메모리 회수
					for (int i = 0; i < people_Number; i++) {
						free(users[i].user_Object);
					}
					free(users);
				}
				printf("==================================\n");
				printf("총 인원 수를 적어주세요>>");
				scanf_s("%d", &people_Number);
				if (people_Number <= 1) { //인원수 제한
					printf("인원 수가 적어 불가능합니다.\n");
					break;
				}
				users = (user*)malloc(people_Number * sizeof(user)); //동적메모리 할당
				for (int i = 0; i < people_Number; i++) {
					printf("%d번째 인원 이름을 적어주세요>>", i+1);
					scanf("%s", &users[i].user_Name);
					users[i].user_Number = (i + 1);
					users[i].user_object_number = 1;
					if (objects != NULL) {
						users[i].user_Object = (object*)malloc(users[i].user_object_number * sizeof(object)); //입찰자 소지물품 동적메모리 할당 (object 1개크기(NULL방지))
					}
					if (first_money != 0) { //초기 자금이 설정됐으면 자금부여
						users[i].user_Money = first_money;
					}
				}
				system("cls");
			}
			else if (choice == 4) { //기타설정(초기자금 및 입찰 시간)
				system("cls");
				printf("==================================\n");
				printf("1. 초기자금설정\n");
				printf("2. 입찰시간 설정\n");
				printf("3. 설명 건너뛰기 설정\n");
				printf("4. 뒤로가기\n");
				printf("==================================\n");
				printf("메뉴 번호>>");
				scanf_s("%d", &choice);
				printf("==================================\n");
				if (choice == 1) { //초기 자금 설정
					printf("초기에 가지고 있을 자금을 적어주세요>>");
					scanf_s("%d", &first_money);
					if (people_Number != 0) { //인원 추가 설정이 됐으면 자금 부여
						for (int i = 0; i < people_Number; i++) {
							users[i].user_Money = first_money;
						}
					}
					system("cls");
				}
				else if (choice == 2) { //입찰 시간 설정
					printf("입찰시간을 적어주세요>>");
					scanf_s("%d", &bid_time);
					system("cls");
				}
				else if (choice == 3) { //설명 건너뛰기 여부
					if (skip == 0) {
						skip = 1;
						system("cls");
					}
					else {
						skip = 0;
						system("cls");
					}
				}
				else if (choice == 4) { system("cls"); continue; } //뒤로가기
				else { //숫자 오류 방지
					printf("==================================\n");
					printf("정확한 숫자로 입력해주세요.\n");
					continue;
				}
			}
			else if (choice == 5) { system("cls"); continue; }
			else {
				printf("==================================\n");
				printf("정확한 숫자로 입력해주세요.\n");
				continue;
			}
		}
		else if (choice == 2) { //경매 시작
			int bidding_usernumber = 0; //현재 입찰 한 인원
			int bidding_people = 0; //입찰 인원 수
			int bidding_money = 0; //입찰 한 금액
			int tmp_money = 0; //현재 입찰 최소 금액
			int bid_end = 0; //최종입찰 체크
			int bid_result_person = 0; //경매 최종 입찰자
			int bid_term = 0; //입찰 횟수
			int len = 3; //입력 문자열 길이 (초기자금 최소 1자릿수, 입찰자 번호 최소 1자릿수, 띄어쓰기)
			int tmp = first_money;
			while (1) { if (tmp < 10) break; tmp = tmp / 10; len++; } //초기 자금 자릿수
			tmp = people_Number;
			while (1) { if (tmp < 10) break; tmp = tmp / 10; len++; } //입찰자 명 수의 자릿수
			char* inputs = (char*)malloc((len * sizeof(char))+1);
			if (people_Number <= 0 || object_Number <= 0) { //경매 시작 오류 방지
				printf("==================================\n");
				printf("경매 설정 후 시작해주세요.\n");
				break;
			}
			else {
				printf("==================================\n");
				printf("경매를 시작하겠습니다.\n현재 초기금액: %d\n입찰 시간: %d초\n", first_money, bid_time);
				printf("=================현재 참여 인원===============\n"); //현재 참여 인원 소개
				for (int i = 0; i < people_Number; i++) {
					printf("%d. %s >> %d\n", users[i].user_Number, users[i].user_Name, users[i].user_Money);
					Sleep(1000);
				}
				printf("===================물품 순서==================\n"); //현재 설정된 물품 순서
				for (int i = 0; i < object_Number; i++) {
					printf("%d. %s\n", (i + 1), objects[i].object_Name);
					Sleep(1000);
				}
				if (skip == 0) {
					printf("==================================\n"); //경매 설명
					printf("입찰 시도할때는 (유저번호) 아니면 (유저번호 입찰금액) 형식으로 입력해주시기 바랍니다.\n");
					Sleep(1000);
					printf("처음 금액 호명하고 %d초가 지나기 3초 전 금액을 1초에 1번씩 호명한 후 경매가 완료됩니다.\n", bid_time);
					Sleep(1000);
					printf("시간 내에 현재 입찰금액보다 높은 금액을 제시하면 입찰이 가능합니다.\n");
					Sleep(1000);
					printf("금액은 입찰금액을 적은게 아니면 10\%씩 상승합니다.\n");
					Sleep(1000);
					printf("시작합니다.\n");
					Sleep(2000);
				}
				system("cls");
				for (int i = 0; i < object_Number; i++) { //경매 시작 (총 i개의 물품)
					printf("==================================\n");
					printf("%d 번째 물품은 %s, %d원부터 시작하겠습니다.\n", i + 1, objects[i].object_Name, objects[i].object_Money);
					tmp_money = objects[i].object_Money;
					Sleep(1000);
					while (1) {
						printf("현재 입찰 최소금액>>%d원\n", tmp_money); //현재 입찰 최소금액 소개
						bidding_people = 0;
						bid_end = 0;
						for (int j = 0; j < (bid_time * 10); j++) { //입찰 기능(딜레이 시간)
							if (kbhit()) { //키보드가 입력할 때 입력함수가 활성화 되게끔 만든다.
								if (gets_s(inputs, len+1)) { //입찰자 및 입찰금액 제시
									for (int k = 0; k < len; k++) { if (inputs[j] == '\n') inputs[j] = '\0'; if (inputs[j] == NULL) inputs[j] = '\0'; } //개행문자 제거 및 NULL 제거
									if (strlen(inputs) > 1) { //글자 길이가 2개이상 (입찰금액까지 적으면,)
										bidding_usernumber = atoi(strtok(inputs, " "));
										bidding_money = atoi(strtok(NULL, " ")); //정수 2개 추출
									}
									else{ bidding_usernumber = atoi(inputs); bidding_money = NULL; } //길이 1개일때 입찰자 번호 추출
									if (bid_result_person == bidding_usernumber && bidding_usernumber != 0) { //동일 입찰자 예외
										printf("이전 입찰자와 동일합니다.\n");
										continue;
									}
									if (bidding_usernumber != NULL && bidding_money == NULL) {
										if (users[bidding_usernumber - 1].user_Money < tmp_money) { //갖고 있는 금액이 부족할 경우
											printf("돈이 부족해 입찰이 불가능합니다.\n");
											printf("현재 가지고 계신 돈은 %d원입니다.\n", users[bidding_usernumber - 1].user_Money);
											bidding_usernumber = 0;
										}
										else { //입찰 성공
											objects[i].object_Money = tmp_money; //입찰금액 저장
											tmp_money *= 1.1;
											bid_result_person = bidding_usernumber; //입찰자 저장
											bidding_people++;
											bid_term++;
											printf("현재 입찰자>>%s\n", users[bid_result_person - 1].user_Name);
											printf("현재 입찰 된 금액>>%d원\n", objects[i].object_Money);
											break;
										}
									}
									if(bidding_usernumber != NULL && bidding_money != NULL) {
										if (users[bidding_usernumber - 1].user_Money < bidding_money) { //금액이 부족할 경우
											printf("돈이 부족해 입찰이 불가능합니다.\n");
											printf("현재 가지고계신 돈은 %d원입니다.\n", users[bidding_usernumber - 1].user_Money);
											bidding_usernumber = 0;
											bidding_money = 0;
										}
										else if (bidding_money >= tmp_money) { //이전 금액보다 크고 가진 금액안에서 입찰 가능한 경우 (입찰성공)
											tmp_money = bidding_money * 1.1;
											objects[i].object_Money = bidding_money;
											bid_result_person = bidding_usernumber; //입찰자 저장
											bidding_people++;
											bid_term++;
											printf("현재 입찰자>>%s\n", users[bid_result_person - 1].user_Name);
											printf("현재 입찰 된 금액>>%d\n", objects[i].object_Money);
											break;
										}
										else { //현재 입찰필요 금액보다 낮을 경우
											printf("현재 입찰금액보다 낮아 불가능합니다.\n");
											bidding_usernumber = 0;
											bidding_money = 0;
										}
									}
								}
							}
							Sleep(100); //딜레이(100ms마다 입찰 인식)
							if ((bid_time * 10) - j == 30 || (bid_time * 10) - j == 20 || (bid_time * 10) - j == 10) {
								printf("%d원\n", objects[i].object_Money); //최종 입찰 3초 전 3번 입찰금액 부르기
								if ((bid_time * 10) - j == 10) {
									bid_end++;
									break;
								}
							}
						}
						printf("==================================\n");
						if (bid_term == 0) { //입찰이 없을때 다음 입찰로 넘기는 기능
							if (i != object_Number - 1) { printf("입찰 인원이 없어 다음 물품으로 넘어갑니다.\n"); }
							else { printf("입찰 인원이 없어 경매를 종료합니다.\n"); }
							bidding_usernumber = 0;
							bidding_money = 0;
							bid_result_person = 0;
							tmp_money = 0; //초기화
							break;
						}
						else if (bid_end > 0) { //최종 입찰
							users[bid_result_person - 1].user_Money -= objects[i].object_Money; //입찰자 소지금액 차감
							users[bid_result_person - 1].user_Object[users[bid_result_person - 1].user_object_number - 1] = objects[i]; //입찰자 소지물품 추가
							users[bid_result_person - 1].user_object_number++; //입찰자 소지물품 갯수
							if (i != object_Number - 1) { //마지막 물품 등록 후 메모리 재할당 제한(메모리 누수 방지)
								users[bid_result_person - 1].user_Object = (object*)realloc(users[bid_result_person - 1].user_Object, users[bid_result_person - 1].user_object_number * sizeof(object));
								//입찰자 소지 물품 동적메모리 재할당 (물품 추가 될 때 마다 1칸식 늘어남)
							}
							printf("현재 %s의 남은 금액>>%d원\n", users[bid_result_person - 1].user_Name, users[bid_result_person - 1].user_Money);
							bid_end = 0;
							bid_result_person = 0;
							bidding_usernumber = 0;
							bidding_money = 0;
							tmp_money = 0;
							bid_term = 0; //초기화
							break;
						}
					}
				}
				system("cls");
				for (int i = 0; i < people_Number; i++) { //최종 결과
					printf("%s의 물품\n", users[i].user_Name);
					printf("----------------------------------\n");
					if (users[i].user_object_number == 1) {
						printf("소지한 물품이 없습니다.\n");
					}
					else {
						for (int j = 0; j < users[i].user_object_number - 1; j++) { printf("%d. %s>>%d원\n", j + 1, users[i].user_Object[j].object_Name, users[i].user_Object[j].object_Money); }
						//포인터로 받은 변수 전부 불러오기
					}
					printf("==================================\n");
					printf("남은 금액>>%d\n", users[i].user_Money);
					printf("==================================\n\n");
				}
				continue;
			}
		}
		else if (choice == 3) { //경매 초기화
			system("cls");
			printf("경매 초기화 시작\n");
			if (users != NULL) { //오류 방지
				for (int i = 0; i < people_Number; i++) {
					free(users[i].user_Object);
				}
				free(users); //메모리 회수
			}
			else { printf("아직 설정이 안됐습니다.\n"); continue; }
			if (objects != NULL) { //오류 방지
				free(objects); //메모리 회수
			}
			else { printf("아직 설정이 안됐습니다.\n"); continue; }
			people_Number = 0; //기초 설정에 사용한 변수 초기화
			object_Number = 0;
			first_money = 10000;
			bid_time = 15;
			printf("경매 초기화 완료\n"); //초기화 완료 표시
		}
		else if (choice == 4) { //프로그램 종료
			printf("==================================\n");
			printf("경매 프로그램을 종료합니다.");
			if (users != NULL) { //오류 방지
				for (int i = 0; i < people_Number; i++) {
					free(users[i].user_Object);
				}
				free(users); //메모리 회수
			}
			if (objects != NULL) { //오류 방지
				free(objects); //메모리 회수
			}
			break;
		}
		else { //숫자 입력 오류 방지
			printf("정확한 숫자로 입력해주세요\n");
			continue;
		}
	}
	return 0;
}