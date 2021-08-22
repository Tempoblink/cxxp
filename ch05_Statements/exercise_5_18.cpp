/*
 * 说明下列循环的含义并改正其中的错误。
 *
 * (a) do 
 *        int v1, v2;
 *        cout << "Please enter two numbers to sum:";
 *        if(cin >> v1 >> v2)
 *            cout << "Sum is: " << v1 + v2 << endl;
 *     while(cin);
 *
 * (b) do {
 *        // ...
 *     } while(int ival = get_response());
 *
 * (c) do {
 *        int ival = get_response();
 *     } while (ival);
 */

/*
 * (a) do { 
 *        int v1, v2;
 *        cout << "Please enter two numbers to sum:";
 *        if(cin >> v1 >> v2)
 *            cout << "Sum is: " << v1 + v2 << endl;
 *     } while(cin);
 *
 * (b) int ival = get_response();
 *     do {
 *        // ...
 *     } while(ival = get_response());
 *
 * (c  int ival = get_response();
 *     do {
 *
 *     } while (ival);
 */

int main(void) {
    return 0;
}
