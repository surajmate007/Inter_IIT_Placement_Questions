// easy solution:

using namespace std;
int main() {
    string keyboard = "abcdefghijklmnopqrstuvwxy", text = "cba";
    map<char,int> m;
    for(int i = 0; i < keyboard.length(); i++){
        m[keyboard[i]] = i;
    }
    int time = 0, current_index = 0;
    for(char c : text){
        time += abs(m[c] - current_index);
        current_index = m[c];
    }
    cout << time << endl;
    return 0;
}
