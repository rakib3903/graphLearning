#include<bits/stdc++.h>
using namespace std;

int main() {

    int m;
    cin >> m;
    int arr[m][m];
    int Am[m][m];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << endl << endl;
    int grph[m][m][m];

    for(int i = 0; i < m; i++) {
        if(i == 0) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    grph[i][j][k] = arr[j][k];
                    Am[j][k] = arr[j][k];
                }
            }
        } else {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    for(int p = 0; p < m; p++) {
                        sum += grph[i-1][j][p] * arr[p][k];
                    }
                    grph[i][j][k] = sum;
                    Am[j][k] += sum;
                    sum = 0;
                }
            }

        }

    }

    for(int i = 0; i < m; i++) {
        cout << "A^" << i+1 << " :" << endl;
        for(int j =0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                cout << grph[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }

    cout << "[Am] :" << endl;

    for(int j = 0; j < m; j++) {
        for(int k = 0; k < m; k++) {
            cout << Am[j][k] << " ";
        }
        cout << endl;
    }

    int bol = -1;
    cout << endl << endl << "Path Matrix :" << endl;

    for(int j = 0; j < m; j++) {
        for(int k = 0; k < m; k++) {
            if(Am[j][k] > 0) {
                cout << 1 << " ";
            } else {
                bol = bol + 1;
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    if(bol ==  -1) {
        cout << "The  graph is complete graph." << endl;
    } else {
        cout << "The graph is not complete graph." << endl << endl;
    }

    return 0;

}
