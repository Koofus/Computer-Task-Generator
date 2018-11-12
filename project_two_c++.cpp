#include <iostream>
#include <queue>
#include <string>
#include <windows.h>

using namespace std;

class Task
{
	private:
		string name;
		int priority = 0;
	public:
		void set_name(string name);
		void set_priority(int new_priority);
		void display_name();
		int return_priority();
		
};

void Task::set_name(string new_name_set)
{
	name = new_name_set;
}

void Task::set_priority(int new_priority)
{
	priority = new_priority;
}

void Task::display_name()
{
	cout << name << endl;
}
int Task::return_priority()
{
	return priority;
}


class Task_master
{	private:
		struct Compare_Priority {
			bool operator()(Task p1, Task p2) {
		//return "true" if "p1" is ordered before "p2"
				return p1.return_priority() < p2.return_priority();
			}
		};
		priority_queue<Task, vector<Task>, Compare_Priority> task_manager;
	public:
		void add(Task value);
		void process(Task new_task);
		void create_task();
		void print_queue();
		int task_generator();
		void pop();
		Task top();
		bool empty();
		
		
};



bool Task_master::empty()
{
	return task_manager.empty();
}

Task Task_master::top()
{
	return task_manager.top();
}

void Task_master::pop()
{
	task_manager.pop();
}
void Task_master::add(Task value) 
{

	task_manager.push(value);
	
}

void Task_master::print_queue()
{
	while(!task_manager.empty())
	{
		Task task = top();
		task.display_name();
		pop();
	}
}
void Task_master::create_task()
{
	string name;
	int priority;
	cout << "Enter the name of the task.." << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter the priority of the task" << endl;
	cin >> priority;
	Task new_task;
	new_task.set_name(name);
	new_task.set_priority(priority);
	task_manager.push(new_task);
	
}

int Task_master::task_generator()
{
	int number_of_tasks;
	cout << "How many tasks do you want to add" << endl;
	cin >> number_of_tasks;
	for(int i = 0; i < number_of_tasks; i++)
	{
		create_task();
	}
	return 0;
}

void Task_master::process(Task new_task)
{
	cout << "Computer is generating the next task to complete";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << "." << endl;
	Sleep(150);
	cout << "Computer is processing task: ";
	Sleep(200);
	new_task.display_name();
	Sleep(150);
	cout << "Computer is finishing the task: ";
	Sleep(200);
	new_task.display_name();
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	cout << "Computer is finished" << endl;
	cout << "Load next task y/n\n";
	cin >> load_task;
	if (load_task == 'n') {
		break;
	}

		
}

int main()
{	
	Task_master master_queue;
	Task task1, task2, task3, task4, task5, task6, task7, task8, task9;
	task1.set_name("Launch the Rocket!");
	task1.set_priority(4);
	task2.set_name("Connect the Fuel Lines");
	task2.set_priority(5);
	task3.set_name("Train the Astronauts");
	task3.set_priority(6);
	task4.set_name("Get the Rocket");
	task4.set_priority(7);
	task5.set_name("Pop popcorn");
	task5.set_priority(9);
	task6.set_name("Make a windmill");
	task6.set_priority(2);
	task7.set_name("Fly a kite");
	task7.set_priority(1);
	task8.set_name("Read a book");
	task8.set_priority(8);
	task9.set_name("Eat the popcorn");
	task9.set_priority(3);
	
	while(true)
	{
	cout << "Which Task Would You like to do" << endl;
	cout << "Press 1 : Launch the Rocket!" << endl;
	cout << "Press 2 : Connect the Fuel Lines" << endl;
	cout << "Press 3 : Train the Astronauts" << endl;
	cout << "Press 4 : Get the Rocket" << endl;
	cout << "Press 5 : To pop popcorn" << endl;
	cout << "Press 6 : To Make a windmill" << endl;
	cout << "Press 7 : To Fly a Kite" << endl;
	cout << "Press 8 : Read a Book" << endl;
	cout << "Press 9 : To eat the popcorn" << endl;
	cout << "Press 10 : To add additional tasks" << endl;
	cout << "Press 0 to end the madness" << endl;
	if(master_queue.empty())
	{
		int choice = -1;
		while(choice != 0)
		{
		
		cin >> choice;
		
			if(choice == 1)
			{
				master_queue.add(task1);
			}
			
			if(choice == 2)
			{
				master_queue.add(task2);
			}
			if(choice == 3)
			{
				master_queue.add(task3);
			}
			if(choice == 4)
			{
				master_queue.add(task4);
			}
			if(choice == 5)
			{
				master_queue.add(task5);
			}
			if(choice == 6)
			{
				master_queue.add(task6);
			}
			if(choice == 7)
			{
				master_queue.add(task7);
			}
			if(choice == 8)
			{
				master_queue.add(task8);
			}
			if(choice == 9)
			{
				master_queue.add(task9);
			}
			if(choice == 10)
			{
				master_queue.task_generator();
			}
			
			
			
		}
   }
    system("cls");

	while (!master_queue.empty())
	{
	string choice;
	cout << "Do you want to remove the next task / add a task or stop the program" << endl;
	cin >> choice;
	if (choice == "remove") {
		cout << "The item has been removed" << endl;
		master_queue.pop();
		
	}
	else if (choice == "add") {
		master_queue.create_task();
	}
	else if (choice == "stop") {
		break;
	}
	else {
		continue;
	}
	Task task = master_queue.top();
	master_queue.process(task);
	master_queue.pop();
	Sleep(800);
	system("cls");
	}

	}
	return 0;

	
}
