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


int add_task(TaskList* list, char new_node, int id);
