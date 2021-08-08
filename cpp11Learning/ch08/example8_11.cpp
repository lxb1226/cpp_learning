void DoSomething1();
void DoSomething2();

[[ noreturn ]] void ThrowAway(){
    throw "expection";
}

void Func(){
    DoSomething1();
    ThrowAway();
    DoSomething2();
}