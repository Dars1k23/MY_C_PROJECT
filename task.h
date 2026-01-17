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
int mark_done(TaskList* list, int target_id);
int del_task(TaskList* list, int target_id)
int run();

