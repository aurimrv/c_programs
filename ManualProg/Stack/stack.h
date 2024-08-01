
struct stack_node
{
    struct stack_node *above;
    int data;
    struct stack_node *below;
};

typedef struct stack_node stack_list;
typedef stack_list *link;

void join(link above, link below);
int push(int value);
int pop();
int isEmpty();
int removeBottom(); 
void print_stack();

