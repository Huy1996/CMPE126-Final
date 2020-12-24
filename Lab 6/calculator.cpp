//
// Created by minhh on 10/20/2020.
//

#include "Calculator.h"
//--------------------------Expressionstream section--------------------------------
bool is_number(char c);
expressionstream::expressionstream(const string &string_in) : buffer(string_in)
{
    current_pos = buffer.begin();
    next_position = current_pos;
    skip_space();
}

void expressionstream::skip_space()
{
    while(*current_pos == ' ' && current_pos != buffer.end())
        ++current_pos;
    while(*next_position == ' ' && next_position != buffer.end())
        ++next_position;
}

string expressionstream::get_number()
{
    bool is_negative = false;
    string::iterator number_start;
    if (*current_pos == '-') is_negative = true;
    number_start = current_pos;
    while(number_start != buffer.end() && !is_number(*number_start))
        ++number_start;
    next_position = number_start;
    while(next_position != buffer.end() && is_number(*next_position))
        ++next_position;
    if(is_negative)
        return '-' + string(number_start, next_position);
    else
        return string(number_start, next_position);
}

bool expressionstream::is_negative(){
    string::iterator negative_check = next_position - 1;
    while (negative_check != buffer.begin() && *negative_check == ' ')
        --negative_check;
    return (!is_number(*negative_check) && *negative_check != ')');

}

string expressionstream::get_next_token()
{
    skip_space();
    current_pos = next_position;
    return get_current_token();
}

string expressionstream::get_current_token()
{
    skip_space();
    if(current_pos == buffer.end())
        return "\0";
    next_position = current_pos;
    if(next_token_is_int())
        return get_number();
    ++next_position;
    return string(current_pos, next_position);
}

bool expressionstream::next_token_is_int()
{
    skip_space();
    if(is_number(*next_position))
        return true;
    if(*next_position != '-')
        return false;
    return is_negative();
}

bool expressionstream::next_token_is_op() {
    skip_space();
    if (next_token_is_int())
        return false;
    return (*next_position == '+' || *next_position == '-' || *next_position == '*' || *next_position == '/' || *next_position == '!' || *next_position == '^' || *next_position == '%');
}

bool expressionstream::next_token_is_open_paren(){
    skip_space();
    return *next_position == '(';
}

bool expressionstream::next_token_is_close_paren(){
    skip_space();
    return *next_position == ')';
}

bool is_number(char c) {
    return (c >= '0' && c <= '9' || c >='A' && c <='Z' || c >='a' && c <='z' || c == '.');
}
//----------------------------Node section------------------------------------//
node::node(string input)
{
    data = input;
    next = nullptr;
}

node::~node() = default;
//----------------------------Stack section-----------------------------------//
stack::stack()
{
    head = nullptr;
    tail = nullptr;
}

stack::stack(string data)
{
    head = nullptr;
    tail = nullptr;
    push(data);
}

stack::stack(const stack &original)
{
    node *temp = original.head;
    head= nullptr;
    tail= nullptr;
    while(temp)
    {
        push(temp->data);
        temp = temp->next;
    }

}

stack::~stack()
{
    node *current = head;
    node *delete_node;
    while(current)
    {
        delete_node = current;
        current = current->next;
        delete delete_node;
    }
    head = nullptr;
    tail = nullptr;
}

void stack::push(string input)
{
    node *temp = new node(input);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

string stack::top()
{
    if(empty())
        throw std::exception();
    else
        return tail->data;
}

void stack::pop()
{
    if(empty())
        throw std::exception();
    else if(size() == 1)
    {
        node *temp = head;
        head = nullptr;
        tail = nullptr;
        delete temp;
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < size() - 2; i++)
            temp = temp->next;
        tail = temp;
        temp = temp->next;
        delete temp;
        tail->next = nullptr;
    }
}

bool stack::empty()
{
    return size() == 0 ? true : false;
}

unsigned stack::size() const
{
    if(head == nullptr)
        return 0;
    else
    {
        int to_return = 0;
        node *temp = head;
        while(temp)
        {
            to_return++;
            temp = temp->next;
        }
        return to_return;
    }
}

stack& stack::operator=(const stack &RHS)
{
    if(this == &RHS)
        return *this;
    else
    {
        this->~stack();
        node *temp = RHS.head;
        while(temp)
        {
            push(temp->data);
            temp = temp->next;
        }
    }
}
//----------------------------Queue Section-----------------------------------//
queue::queue()
{
    head = nullptr;
    tail = nullptr;
}

queue::queue(string data)
{
    head = nullptr;
    tail = nullptr;
    enqueue(data);
}

queue::queue(const queue &original)
{
    node *temp = original.head;
    head = nullptr;
    tail = nullptr;
    while(temp)
    {
        enqueue(temp->data);
        temp = temp->next;
    }
}

queue::~queue()
{
    node *current = head;
    node *delete_node;
    while(current)
    {
        delete_node = current;
        current = current->next;
        delete delete_node;
    }
    head = nullptr;
    tail = nullptr;
}

void queue::enqueue(string data)
{
    node *temp = new node(data);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

string queue::top()
{
    if(empty())
        throw std::exception();
    else
        return head->data;
}

void queue::dequeue()
{
    if(empty())
        throw std::exception();
    else if(size() == 1)
    {
        node *temp = head;
        head = nullptr;
        tail = nullptr;
        delete temp;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

bool queue::empty()
{
    return size() == 0 ? true : false;
}

unsigned queue::size() const
{
    if(head == nullptr)
        return 0;
    else
    {
        int to_return = 0;
        node *temp = head;
        while(temp)
        {
            to_return++;
            temp = temp->next;
        }
        return to_return;
    }
}

queue& queue::operator=(const queue &RHS)
{
    if(this == &RHS)
        return *this;
    else
    {
        this -> ~queue();
        node *temp = RHS.head;
        while(temp)
        {
            enqueue(temp->data);
            temp = temp->next;
        }
    }
}

std::ostream& operator<<(std::ostream &stream, queue &RHS) {
    node *current = RHS.head;
    stream << current->data;
    current = current->next;
    while(current)
    {
        stream << " " << current->data;
        current = current->next;
    }
    return stream;
}
//--------------------------Calculator section--------------------------------//
int operator_priority(string op);

int cal(int lhs, int rhs, string op){
    std::string::iterator op_iter = op.begin();
    switch (*op_iter){
        case '^': return (int)pow(lhs, rhs);
        case '*': return lhs * rhs;
        case '/': return lhs / rhs;
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '%': return lhs % rhs;
        default: throw "unknown operator";
    }
}

bool is_number(std::string input_string){
    if (input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "%" || input_string == "(" || input_string == ")" || input_string == "^" || input_string == "!")
        return false;
    else
        return true;
}

bool is_operator(std::string input_string){
    if (input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "%" || input_string == "^" || input_string == "!")
        return true;
    else
        return false;
}
void calculator::getInfix()
{
    do
    {
        cout << "Enter the infix: ";
        string input;
        getline(cin, input);
        if(check_valid(input))
        {
            expressionstream *stream = new expressionstream(input);
            while(true)
            {
                if(stream->get_next_token() == "\0")
                    break;
                infix.enqueue(stream->get_current_token());
            }
            break;
        }
        cout << "Invalid input.\n\n";
    }
    while(true);
}

bool calculator::check_valid(const string &input)
{
    expressionstream *stream = new expressionstream(input);
    int count_paren_open = 0;
    if(stream -> next_token_is_op())
        return false;
    else
    {
        do
        {
            if(stream->next_token_is_int())
            {
                stream->get_next_token();
                if (stream->next_token_is_int())
                    return false;
            }
            else if(stream->next_token_is_op())
            {
                stream->get_next_token();
                if (stream -> next_token_is_op())
                    return false;
            }
            else if(stream->next_token_is_open_paren())
            {
                stream->get_next_token();
                count_paren_open++;
            }
            else if(stream->next_token_is_close_paren())
            {
                if (count_paren_open == 0)
                {
                    return false;
                }
                else
                {
                    stream->get_next_token();
                    count_paren_open--;
                }
            }
            else break;
        }
        while(true);
        if(count_paren_open != 0)
            return false;
        return true;
    }
}

void calculator::convertToPostfix()
{
    queue temp = infix;
    stack temp_stack;
    string temp_string;
    while(!temp.empty())
    {
        temp_string = temp.top();
        temp.dequeue();
        if(is_number(temp_string))
        {
            postfix.enqueue(temp_string);
        }
        else if(is_operator(temp_string))
        {
            while(!temp_stack.empty() && operator_priority(temp_stack.top()) >= operator_priority(temp_string) && temp_stack.top() != "(")
            {
                postfix.enqueue(temp_stack.top());
                temp_stack.pop();
            }
            temp_stack.push(temp_string);
        }
        else if(temp_string == "(")
        {
            temp_stack.push(temp_string);
        }
        else if(temp_string == ")")
        {
            while(temp_stack.top() != "(")
            {
                postfix.enqueue(temp_stack.top());
                temp_stack.pop();
            }
            temp_stack.pop();
            continue;
        }
    }
    while(!temp_stack.empty())
    {
        postfix.enqueue(temp_stack.top());
        temp_stack.pop();
    }
}

void calculator::showInfix()
{
    cout << "Infix Expression: " << infix << endl;
}

void calculator::showPostfix()
{
    convertToPostfix();
    cout << "Postfix Expression: " << postfix << endl;
}


int operator_priority(string op)
{
    if (op == "!")
        return 4;
    else if (op == "^" )
        return 3;
    else if (op == "/" || op == "*" || op == "%")
        return 2;
    else if (op == "+" || op == "-")
        return 1;
    else
        return 0;
}

int calculator::calculate()
{
    stack cal_stack;
    queue cal_queue;
    cal_queue = postfix;
    int left, right;
    string op;
    while(!cal_queue.empty())
    {
        while(is_number(cal_queue.top()))
        {
            cal_stack.push(cal_queue.top());
            cal_queue.dequeue();
            if(cal_queue.empty())
                break;
        }
        if(cal_queue.empty())
            break;
        op = cal_queue.top();
        cal_queue.dequeue();
        if(op == "!")
        {
            left = stoi(cal_stack.top());
            cal_stack.pop();
            int j=1;
            for(int i = 1; i <= left; i++)
                j=j*i;
            cal_stack.push(to_string(j));
        }
        else
        {
            right = stoi(cal_stack.top());
            cal_stack.pop();
            left = stoi(cal_stack.top());
            cal_stack.pop();

            string result = to_string(cal(left, right, op));
            cal_stack.push(result);
        }
    }
    return stoi(cal_stack.top());
}