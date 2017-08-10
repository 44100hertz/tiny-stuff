#define TAPE_SIZE 256
#define < head = (head+1) % TAPE_SIZE;
#define > head = (head-1) % TAPE_SIZE;
#define + ++tape[head];
#define - --tape[head];
#define . putchar(tape[head]);
#define , tape[head] = getchar();
#define [ while(tape[head]) {
#define ] }

int main()
{
    char tape[TAPE_SIZE];
    int head = 0;

    ++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
}


