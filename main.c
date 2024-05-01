#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


typedef struct object {
	int object_Money; //��ǰ ����
	int object_Number; //��ǰ ��ȣ
	char object_Name[100]; //��ǰ �̸�
} object;

typedef struct user {
	int user_Money; //������ �����ݾ�
	int user_Number; //������ ��ȣ
	int user_object_number; //������ ������ǰ ����
	char user_Name[100]; //������ �̸�
	object* user_Object; //������ ������ǰ (������)
} user;

int main() {
	int choice = 0;
	int skip = 0; //���� ��ŵ
	int people_Number = 0; //�����ο� ��
	int object_Number = 0; //��ǰ ��
	int first_money = 10000; //�ʱ� �ڱ� �⺻���� ����
	int bid_time = 15; //���� �ð� �⺻���� 15��
	user* users; //������
	users = NULL; //NULL�� �ʱ�ȭ
	object* objects = (object*)malloc(object_Number * sizeof(object)); //������ �� �����Ҵ� (0ĭ(NULL))
	while (1) {
		printf("���� ����\n");
		printf("==================================\n\n");
		printf("�ο� ���\n");
		printf("----------------------------------\n");
		if (people_Number == 0) { printf("������ �ο��� �����ϴ�.\n"); } //����ó��
		else { for (int i = 0; i < people_Number; i++) { printf("%d. %s\n", i + 1, users[i].user_Name); } } //������ ���
		printf("==================================\n\n");
		printf("��ǰ ���\n");
		printf("----------------------------------\n");
		if (object_Number == 0) { printf("������ ��ǰ�� �����ϴ�.\n"); } //����ó��
		else { for (int i = 0; i < object_Number; i++) { printf("%d. %s>>%d��\n", i + 1, objects[i].object_Name, objects[i].object_Money); } } //��ǰ ���
		printf("==================================\n");
		printf("�ʱ� �ڱ�: %d��\n", first_money);
		printf("���� �ð�: %d��\n", bid_time);
		if (skip == 0) { printf("���� �ǳʶٱ�: ��Ȱ��ȭ\n"); }
		else { printf("���� �ǳʶٱ�: Ȱ��ȭ\n"); }
		printf("==================================\n\n"); //���� ����

		printf("==================================\n");
		printf("1. ��� ����\n");
		printf("2. ��� ����\n");
		printf("3. ��� �ʱ�ȭ\n");
		printf("4. ����\n");
		printf("==================================\n");
		printf("�޴� ��ȣ>>");
		scanf_s("%d", &choice);
		system("cls");
		if (choice == 1) { //��� ����
			printf("==================================\n");
			printf("1. ��Ź�ǰ ����\n");
			printf("2. ��Ź�ǰ ����\n");
			printf("3. ����ο� ����\n");
			printf("4. ��Ÿ ����\n");
			printf("5. �ڷΰ���\n");
			printf("==================================\n");
			printf("�޴� ��ȣ>>");
			scanf_s("%d", &choice);
			if (choice == 1) { //��Ź�ǰ ����
				if (object_Number != 0) { //���� ����
					printf("�̹� �������ֽ��ϴ�.\n");
					continue;
				}
				printf("==================================\n");
				printf("�� ��ǰ ���� �����ּ���>>");
				scanf_s("%d", &object_Number);
				objects = (object*)realloc(objects, object_Number * sizeof(object)); //�����޸� ���Ҵ�
				for (int i = 0; i < object_Number; i++) {
					printf("==================================\n");
					printf("%d��° ��ǰ �̸��� �����ּ���>>", i + 1);
					scanf("%s", &objects[i].object_Name);
					printf("%d��° ��ǰ ������ �����ּ���>>", i + 1);
					scanf_s("%d", &objects[i].object_Money);
					objects[i].object_Number = (i + 1);
				}
				system("cls");
			}
			else if (choice == 2) { //��� ��ǰ ����
				system("cls");
				printf("==================================\n");
				printf("1. ��Ź�ǰ ��ü\n");
				printf("2. ��Ź�ǰ �߰�\n");
				printf("3. �ڷΰ���\n");
				printf("==================================\n");
				printf("�޴� ��ȣ>>");
				scanf_s("%d", &choice);
				char replace_object[100];
				if (choice == 1) { //��� ��ǰ ��ü
					if (object_Number == 0) { //��������
						printf("==================================\n");
						printf("������ ��ǰ�� �����ϴ�.\n");
						break;
					}
					printf("==================================\n");
					printf("��ü�ϰ� ���� ��ǰ �̸�>>");
					scanf("%s", &replace_object);
					for (int i = 0; i < object_Number; i++) { //��ǰ �̸� �ν�
						if (strcmp(objects[i].object_Name, replace_object) == 0) {
							printf("�����ϰ� ���� �̸��� �����ּ���>>");
							scanf("%s", &objects[i].object_Name);
							printf("%s�� ������ �����ּ���>>", objects[i].object_Name);
							scanf_s("%d", &objects[i].object_Money);
							continue;
						}
					}
					system("cls");
				}
				else if (choice == 2) { //��� ��ǰ �߰�
					int add_object_Number = 0;
					if (object_Number == 0) { //��������
						printf("==================================\n");
						printf("������ ��ǰ�� �����ϴ�.\n");
						break;
					}
					printf("==================================\n");
					printf("�߰��ϰ� ���� �� ��ǰ ���� �����ּ���>>");
					scanf_s("%d", &add_object_Number);
					objects = (object*)realloc(objects, (object_Number + add_object_Number) * sizeof(object)); //�����޸� ���Ҵ�
					for (int i = 0; i < add_object_Number; i++) {
						printf("==================================\n");
						printf("%d��° ��ǰ �̸��� �����ּ���>>", i + 1);
						scanf("%s", &objects[object_Number + i].object_Name);
						printf("%d��° ��ǰ ������ �����ּ���>>", i + 1);
						scanf_s("%d", &objects[object_Number + i].object_Money);
						objects[object_Number + i].object_Number = (object_Number + i + 1);
					}
					object_Number += add_object_Number; //�� ��ǰ ����
					system("cls");
				}
				else if (choice == 3) { system("cls"); continue; } //�ڷΰ���
				else { //��������
					printf("==================================\n");
					printf("��Ȯ�� ���ڷ� �Է����ּ���.\n");
					continue;
				}
				
			}
			else if (choice == 3) { //����ο� ����
				if (users != NULL) { //���� �ο� �缳���� �����Ҵ� �޸� ȸ��
					for (int i = 0; i < people_Number; i++) {
						free(users[i].user_Object);
					}
					free(users);
				}
				printf("==================================\n");
				printf("�� �ο� ���� �����ּ���>>");
				scanf_s("%d", &people_Number);
				if (people_Number <= 1) { //�ο��� ����
					printf("�ο� ���� ���� �Ұ����մϴ�.\n");
					break;
				}
				users = (user*)malloc(people_Number * sizeof(user)); //�����޸� �Ҵ�
				for (int i = 0; i < people_Number; i++) {
					printf("%d��° �ο� �̸��� �����ּ���>>", i+1);
					scanf("%s", &users[i].user_Name);
					users[i].user_Number = (i + 1);
					users[i].user_object_number = 1;
					if (objects != NULL) {
						users[i].user_Object = (object*)malloc(users[i].user_object_number * sizeof(object)); //������ ������ǰ �����޸� �Ҵ� (object 1��ũ��(NULL����))
					}
					if (first_money != 0) { //�ʱ� �ڱ��� ���������� �ڱݺο�
						users[i].user_Money = first_money;
					}
				}
				system("cls");
			}
			else if (choice == 4) { //��Ÿ����(�ʱ��ڱ� �� ���� �ð�)
				system("cls");
				printf("==================================\n");
				printf("1. �ʱ��ڱݼ���\n");
				printf("2. �����ð� ����\n");
				printf("3. ���� �ǳʶٱ� ����\n");
				printf("4. �ڷΰ���\n");
				printf("==================================\n");
				printf("�޴� ��ȣ>>");
				scanf_s("%d", &choice);
				printf("==================================\n");
				if (choice == 1) { //�ʱ� �ڱ� ����
					printf("�ʱ⿡ ������ ���� �ڱ��� �����ּ���>>");
					scanf_s("%d", &first_money);
					if (people_Number != 0) { //�ο� �߰� ������ ������ �ڱ� �ο�
						for (int i = 0; i < people_Number; i++) {
							users[i].user_Money = first_money;
						}
					}
					system("cls");
				}
				else if (choice == 2) { //���� �ð� ����
					printf("�����ð��� �����ּ���>>");
					scanf_s("%d", &bid_time);
					system("cls");
				}
				else if (choice == 3) { //���� �ǳʶٱ� ����
					if (skip == 0) {
						skip = 1;
						system("cls");
					}
					else {
						skip = 0;
						system("cls");
					}
				}
				else if (choice == 4) { system("cls"); continue; } //�ڷΰ���
				else { //���� ���� ����
					printf("==================================\n");
					printf("��Ȯ�� ���ڷ� �Է����ּ���.\n");
					continue;
				}
			}
			else if (choice == 5) { system("cls"); continue; }
			else {
				printf("==================================\n");
				printf("��Ȯ�� ���ڷ� �Է����ּ���.\n");
				continue;
			}
		}
		else if (choice == 2) { //��� ����
			int bidding_usernumber = 0; //���� ���� �� �ο�
			int bidding_people = 0; //���� �ο� ��
			int bidding_money = 0; //���� �� �ݾ�
			int tmp_money = 0; //���� ���� �ּ� �ݾ�
			int bid_end = 0; //�������� üũ
			int bid_result_person = 0; //��� ���� ������
			int bid_term = 0; //���� Ƚ��
			int len = 3; //�Է� ���ڿ� ���� (�ʱ��ڱ� �ּ� 1�ڸ���, ������ ��ȣ �ּ� 1�ڸ���, ����)
			int tmp = first_money;
			while (1) { if (tmp < 10) break; tmp = tmp / 10; len++; } //�ʱ� �ڱ� �ڸ���
			tmp = people_Number;
			while (1) { if (tmp < 10) break; tmp = tmp / 10; len++; } //������ �� ���� �ڸ���
			char* inputs = (char*)malloc((len * sizeof(char))+1);
			if (people_Number <= 0 || object_Number <= 0) { //��� ���� ���� ����
				printf("==================================\n");
				printf("��� ���� �� �������ּ���.\n");
				break;
			}
			else {
				printf("==================================\n");
				printf("��Ÿ� �����ϰڽ��ϴ�.\n���� �ʱ�ݾ�: %d\n���� �ð�: %d��\n", first_money, bid_time);
				printf("=================���� ���� �ο�===============\n"); //���� ���� �ο� �Ұ�
				for (int i = 0; i < people_Number; i++) {
					printf("%d. %s >> %d\n", users[i].user_Number, users[i].user_Name, users[i].user_Money);
					Sleep(1000);
				}
				printf("===================��ǰ ����==================\n"); //���� ������ ��ǰ ����
				for (int i = 0; i < object_Number; i++) {
					printf("%d. %s\n", (i + 1), objects[i].object_Name);
					Sleep(1000);
				}
				if (skip == 0) {
					printf("==================================\n"); //��� ����
					printf("���� �õ��Ҷ��� (������ȣ) �ƴϸ� (������ȣ �����ݾ�) �������� �Է����ֽñ� �ٶ��ϴ�.\n");
					Sleep(1000);
					printf("ó�� �ݾ� ȣ���ϰ� %d�ʰ� ������ 3�� �� �ݾ��� 1�ʿ� 1���� ȣ���� �� ��Ű� �Ϸ�˴ϴ�.\n", bid_time);
					Sleep(1000);
					printf("�ð� ���� ���� �����ݾ׺��� ���� �ݾ��� �����ϸ� ������ �����մϴ�.\n");
					Sleep(1000);
					printf("�ݾ��� �����ݾ��� ������ �ƴϸ� 10\%�� ����մϴ�.\n");
					Sleep(1000);
					printf("�����մϴ�.\n");
					Sleep(2000);
				}
				system("cls");
				for (int i = 0; i < object_Number; i++) { //��� ���� (�� i���� ��ǰ)
					printf("==================================\n");
					printf("%d ��° ��ǰ�� %s, %d������ �����ϰڽ��ϴ�.\n", i + 1, objects[i].object_Name, objects[i].object_Money);
					tmp_money = objects[i].object_Money;
					Sleep(1000);
					while (1) {
						printf("���� ���� �ּұݾ�>>%d��\n", tmp_money); //���� ���� �ּұݾ� �Ұ�
						bidding_people = 0;
						bid_end = 0;
						for (int j = 0; j < (bid_time * 10); j++) { //���� ���(������ �ð�)
							if (kbhit()) { //Ű���尡 �Է��� �� �Է��Լ��� Ȱ��ȭ �ǰԲ� �����.
								if (gets_s(inputs, len+1)) { //������ �� �����ݾ� ����
									for (int k = 0; k < len; k++) { if (inputs[j] == '\n') inputs[j] = '\0'; if (inputs[j] == NULL) inputs[j] = '\0'; } //���๮�� ���� �� NULL ����
									if (strlen(inputs) > 1) { //���� ���̰� 2���̻� (�����ݾױ��� ������,)
										bidding_usernumber = atoi(strtok(inputs, " "));
										bidding_money = atoi(strtok(NULL, " ")); //���� 2�� ����
									}
									else{ bidding_usernumber = atoi(inputs); bidding_money = NULL; } //���� 1���϶� ������ ��ȣ ����
									if (bid_result_person == bidding_usernumber && bidding_usernumber != 0) { //���� ������ ����
										printf("���� �����ڿ� �����մϴ�.\n");
										continue;
									}
									if (bidding_usernumber != NULL && bidding_money == NULL) {
										if (users[bidding_usernumber - 1].user_Money < tmp_money) { //���� �ִ� �ݾ��� ������ ���
											printf("���� ������ ������ �Ұ����մϴ�.\n");
											printf("���� ������ ��� ���� %d���Դϴ�.\n", users[bidding_usernumber - 1].user_Money);
											bidding_usernumber = 0;
										}
										else { //���� ����
											objects[i].object_Money = tmp_money; //�����ݾ� ����
											tmp_money *= 1.1;
											bid_result_person = bidding_usernumber; //������ ����
											bidding_people++;
											bid_term++;
											printf("���� ������>>%s\n", users[bid_result_person - 1].user_Name);
											printf("���� ���� �� �ݾ�>>%d��\n", objects[i].object_Money);
											break;
										}
									}
									if(bidding_usernumber != NULL && bidding_money != NULL) {
										if (users[bidding_usernumber - 1].user_Money < bidding_money) { //�ݾ��� ������ ���
											printf("���� ������ ������ �Ұ����մϴ�.\n");
											printf("���� �������� ���� %d���Դϴ�.\n", users[bidding_usernumber - 1].user_Money);
											bidding_usernumber = 0;
											bidding_money = 0;
										}
										else if (bidding_money >= tmp_money) { //���� �ݾ׺��� ũ�� ���� �ݾ׾ȿ��� ���� ������ ��� (��������)
											tmp_money = bidding_money * 1.1;
											objects[i].object_Money = bidding_money;
											bid_result_person = bidding_usernumber; //������ ����
											bidding_people++;
											bid_term++;
											printf("���� ������>>%s\n", users[bid_result_person - 1].user_Name);
											printf("���� ���� �� �ݾ�>>%d\n", objects[i].object_Money);
											break;
										}
										else { //���� �����ʿ� �ݾ׺��� ���� ���
											printf("���� �����ݾ׺��� ���� �Ұ����մϴ�.\n");
											bidding_usernumber = 0;
											bidding_money = 0;
										}
									}
								}
							}
							Sleep(100); //������(100ms���� ���� �ν�)
							if ((bid_time * 10) - j == 30 || (bid_time * 10) - j == 20 || (bid_time * 10) - j == 10) {
								printf("%d��\n", objects[i].object_Money); //���� ���� 3�� �� 3�� �����ݾ� �θ���
								if ((bid_time * 10) - j == 10) {
									bid_end++;
									break;
								}
							}
						}
						printf("==================================\n");
						if (bid_term == 0) { //������ ������ ���� ������ �ѱ�� ���
							if (i != object_Number - 1) { printf("���� �ο��� ���� ���� ��ǰ���� �Ѿ�ϴ�.\n"); }
							else { printf("���� �ο��� ���� ��Ÿ� �����մϴ�.\n"); }
							bidding_usernumber = 0;
							bidding_money = 0;
							bid_result_person = 0;
							tmp_money = 0; //�ʱ�ȭ
							break;
						}
						else if (bid_end > 0) { //���� ����
							users[bid_result_person - 1].user_Money -= objects[i].object_Money; //������ �����ݾ� ����
							users[bid_result_person - 1].user_Object[users[bid_result_person - 1].user_object_number - 1] = objects[i]; //������ ������ǰ �߰�
							users[bid_result_person - 1].user_object_number++; //������ ������ǰ ����
							if (i != object_Number - 1) { //������ ��ǰ ��� �� �޸� ���Ҵ� ����(�޸� ���� ����)
								users[bid_result_person - 1].user_Object = (object*)realloc(users[bid_result_person - 1].user_Object, users[bid_result_person - 1].user_object_number * sizeof(object));
								//������ ���� ��ǰ �����޸� ���Ҵ� (��ǰ �߰� �� �� ���� 1ĭ�� �þ)
							}
							printf("���� %s�� ���� �ݾ�>>%d��\n", users[bid_result_person - 1].user_Name, users[bid_result_person - 1].user_Money);
							bid_end = 0;
							bid_result_person = 0;
							bidding_usernumber = 0;
							bidding_money = 0;
							tmp_money = 0;
							bid_term = 0; //�ʱ�ȭ
							break;
						}
					}
				}
				system("cls");
				for (int i = 0; i < people_Number; i++) { //���� ���
					printf("%s�� ��ǰ\n", users[i].user_Name);
					printf("----------------------------------\n");
					if (users[i].user_object_number == 1) {
						printf("������ ��ǰ�� �����ϴ�.\n");
					}
					else {
						for (int j = 0; j < users[i].user_object_number - 1; j++) { printf("%d. %s>>%d��\n", j + 1, users[i].user_Object[j].object_Name, users[i].user_Object[j].object_Money); }
						//�����ͷ� ���� ���� ���� �ҷ�����
					}
					printf("==================================\n");
					printf("���� �ݾ�>>%d\n", users[i].user_Money);
					printf("==================================\n\n");
				}
				continue;
			}
		}
		else if (choice == 3) { //��� �ʱ�ȭ
			system("cls");
			printf("��� �ʱ�ȭ ����\n");
			if (users != NULL) { //���� ����
				for (int i = 0; i < people_Number; i++) {
					free(users[i].user_Object);
				}
				free(users); //�޸� ȸ��
			}
			else { printf("���� ������ �ȵƽ��ϴ�.\n"); continue; }
			if (objects != NULL) { //���� ����
				free(objects); //�޸� ȸ��
			}
			else { printf("���� ������ �ȵƽ��ϴ�.\n"); continue; }
			people_Number = 0; //���� ������ ����� ���� �ʱ�ȭ
			object_Number = 0;
			first_money = 10000;
			bid_time = 15;
			printf("��� �ʱ�ȭ �Ϸ�\n"); //�ʱ�ȭ �Ϸ� ǥ��
		}
		else if (choice == 4) { //���α׷� ����
			printf("==================================\n");
			printf("��� ���α׷��� �����մϴ�.");
			if (users != NULL) { //���� ����
				for (int i = 0; i < people_Number; i++) {
					free(users[i].user_Object);
				}
				free(users); //�޸� ȸ��
			}
			if (objects != NULL) { //���� ����
				free(objects); //�޸� ȸ��
			}
			break;
		}
		else { //���� �Է� ���� ����
			printf("��Ȯ�� ���ڷ� �Է����ּ���\n");
			continue;
		}
	}
	return 0;
}