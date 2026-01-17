typedef struct{
	int id;
	char task[256];
	int is_done;
} Task;

typedef struct{
	Task* tasks;
	int count;
	int capacity;
} TaskList;


int add_task(TaskList* list, char new_node, int id); //добавление задачи
int mark_done(TaskList* list, int target_id); //изменение статуса задачи
int del_task(TaskList* list, int target_id) //удаление задачи по ID
int run(); //запуск меню выбора действий
