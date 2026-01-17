#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int add_task(TaskList* list, char new_node, int id){//функция для добавления новой задачи

	if (!list || !new_node || id <= 0 ){ //проверка вхоных данных
		return -1;
	}

	if (list->count >= list->capacity){ //проверка наличия места для новой задачи

		int new_capacity = list->capacity * 2; //если да, расширяем место вдвое

		if (new_capacity == 0){ //если у нас пустой список дел - делаем 10 свободных ячеек для задач

			new_capacity = 10;

		}

		Task* new_tasks = realloc(list->tasks, new_capacity * sizeof(Task)); //выделяем место под новые задачи
		
		list->tasks[list->count].id = id; //задаем значение id
		list->tasks[list->count].task = new_node; //добавляем задачу
		list->tasks[list->count].is_done = 0; //задаем значения выполнения задачи на 0 - не выполнено
		list->count++; //обновляем счетчик имеющихся задач

	}

	return 0;

}

int mark_done(TaskList* list, int target_id){
	
	if (!list || list->count == 0){
		return -1;
	}
	
	for (int i = 0; i < list->count; i++){
		if (list->tasks[i].id == target_id){
			if (list->tasks[i].is_done == 1){
				printf("Задача уже выполнена!");
				return 0; //задача уже выполнена
			}

			list->tasls[i].is_done = 1;
			return 0; //задача успешна найдена, и ее статус изменился
		}
	}

	return -1; //если такой задачи не найдено

}

int del_task(TaskList* list, int target_id){

	if (!list || list->count == 0){
		return -1;
	}

	int idex_del = -1;

	for (int i = 0; i < list->count; i++){
		if (list->tasks[i] == target_id){
			index_del += i;

		}
	}

	if (index_del == -1){
		printf("Такой задачи не найдено!");
		return -1;
	}

	int move_el = list->count - index_del - 1;

	if (move_el > 0){
		memove(
			&list->tasks[index_del], //куда
			&list->tasks[index_del + 1], //откуда
			move_el * sizeof(Task) //колл-во байт
			);
	}

	list->count--; //уменьшаем значение размера

	return 0; //Успешно удалили
}

















int run_main(){
	TaskList list = {0};
	load_tasks(&list, "data/tasks.dat");

	int choice;
	char new_node[256];
	int id;
	int target_id;

	while (1){
		printf("\033[2J\033[H"); //отчистка экрана

		printf("===== TODO MANAGER =====\n"); //меню команд
		printf("Задач: %d\n\n", list.count);
		printf("1. Добавить задачу\n");
		printf("2. Пометить выполненной\n");
		printf("3. Удалить задачу\n");
		printf("4. Показать все задачи\n");
		printf("5. Выход\n\n");
		printf("Выбор: ");

		if (scanf("%d", &choice) != 1){
			while (getchar() != '\n'){ //отчистка буфера
				continue;
			}
		}

	

		switch(choice){
			case 1:
				printf("Описание задачи: ");
				scanf(" %255[^\n]", new_node);
				add_task(&list, new_node, id); //функция добавления новой задачи
				printf("Задача успешно добавлена!\n");
				getchar(); //пауза
				break;
			
			case 2:
				printf("ID задачи: ");
				scanf("%d", &target_id);
				mark_done(&list, target_id); //функция изменения статуса задачи с '0 - невыполено' на '1 - выполнено'
				printf("Успешно отмечено!\n");
				getchar(); //пауза
				break;

			case 3:
				printf("ID для удаления: ");
				scanf("d", &id);
				del_task(&list, id); //функция удаления задачи по id
				printf("Задача успешно удалена! ");
				getchar(); //пауза
				break;

			case 4:
				print_list(&list); //функция вывода всех задач на экран
				printf("\nДля продолжения нажмите Enter....");
				getchar(); //пауза
				break;

			case 5:
				save_task(&list, "data/tasks.dat"); //сохраняем задачи
				free(list.tasks); //отчищаем память
				printf("До свидания!\n");
				return 0;

			default:
				printf("НЕВРНЫЙ ВЫБОР! ПОПРОБУЙТЕ 1-5\n");
				getchar();

		}

	}

}

