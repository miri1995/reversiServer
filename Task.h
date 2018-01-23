#ifndef REVERSISERVER_TASK_H
#define REVERSISERVER_TASK_H


class Task {
public:
    Task(void * (*func)(void *arg), void* arg) : func(func), arg(arg) {}
    void execute() {
        func(arg);
    }
    virtual ~Task() {}
private:
    void * (*func)(void *arg);
    void *arg;
};


#endif //REVERSISERVER_TASK_H
