void callBack();

void call() {
    callBack();
}

void callBack() {
    call();
}

int main() {
    call();
}
