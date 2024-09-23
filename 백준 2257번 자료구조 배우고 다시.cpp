//#include <iostream>
//#include <vector>
//#include <string>
//#include <type_traits>
//#include <cctype>
//using namespace std;
//
////제일 작은 괄호를 찾음
////분자 단위로 화학식량을 각각 구함
////괄호 단위로 잘라서 곱함
//
////1번. 재귀적으로 괄호를 쳐내자
////2번. for문을 돌자  !!!!
//
//int overall_weight = 1;
//
//void print(vector<string> ls) {
//    for (string i : ls) {
//        cout << i << endl;
//    }
//    return;
//}
//
//bool isdecimal(char ch) {
//    return isdigit(ch);
//}
//
//int what_element_is_it(char element) {
//    if (element == 'H') {
//        return 1;
//    }
//    if (element == 'C') {
//        return 12;
//    }
//    if (element == 'O') {
//        return 16;
//    }
//    else{
//        return 0;
//    }
//}
//
////void remove_first_parenthesis(string &chemical_formula) {
////    unsigned long index = size(chemical_formula);
////    if (chemical_formula[0] == '(' && chemical_formula[index - 2] == ')' && isdecimal(chemical_formula[index - 1])) {
////        chemical_formula = chemical_formula.substr(1, index - 3);
////        overall_weight = chemical_formula[index] - '0';
////    }
////    
////    return;
////}
//
//void remove_first_parenthesis(string &chemical_formula) {
//    // 가장 바깥 괄호를 제거하고 가중치를 설정
//    if (chemical_formula[0] == '(') {
//        size_t close_index = chemical_formula.find_last_of(')');
//        if (close_index != string::npos && isdecimal(chemical_formula[close_index + 1])) {
//            overall_weight = chemical_formula[close_index + 1] - '0'; // 가중치 계산
//            chemical_formula = chemical_formula.substr(1, close_index - 1); // 괄호 제거
//        }
//    }
//}
//
//void packaging_elements(vector<string> &divided_elements, const string &chemical_formula) {
//    for (int i = 0; i < size(chemical_formula) - 1; ++i) {
//        string divided_element = "";
//        
//        if (isalpha(chemical_formula[i])) {
//            int j = i + 1;
//            while (chemical_formula[j] != '(' && chemical_formula[j] != ')' && j != size(chemical_formula) - 1) {
//                divided_element = string(divided_element) + chemical_formula[j];
//                j++;
//            }
//        }
//        
//        divided_elements.push_back(divided_element);
//    }
//    return;
//}
//
////void packaging_elements(vector<string> &divided_elements, const string &chemical_formula) {
////    // 화학식을 원소 단위로 분리
////    unsigned long n = chemical_formula.size();
////    string current_element;
////    for (int i = 0; i < n; i++) {
////        if (isalpha(chemical_formula[i])) {
////            current_element = chemical_formula[i];
////            if (i + 1 < n && islower(chemical_formula[i + 1])) {
////                current_element += chemical_formula[i + 1]; // 원소가 두 글자인 경우 처리
////                i++;
////            }
////            divided_elements.push_back(current_element);
////        }
////        else if (isdecimal(chemical_formula[i])) {
////            divided_elements.back() += chemical_formula[i]; // 숫자가 있으면 직전 원소에 붙임
////        }
////    }
////}
//
////int find_molecular_weight(string a_chemical_formula) {
////    int molecular_weight = 0;
////    for (int i = 0; i < size(a_chemical_formula); ++i) {
////        
////        molecular_weight += what_element_is_it(a_chemical_formula[i]);
////        
////        if (isdecimal(a_chemical_formula[i])) {
////            //a_chemical_formula[i] < 10 and a_chemical_formula[i] > 1
////            molecular_weight += what_element_is_it(a_chemical_formula[i - 1]) * (a_chemical_formula[i] - 1);
////
////        }
////    }
////    return molecular_weight;
////}
//
//int find_molecular_weight(const string &a_chemical_formula) {
//    int molecular_weight = 0;
//    unsigned long n = a_chemical_formula.size();
//    for (int i = 0; i < n; i++) {
//        char element = a_chemical_formula[i];
//        if (isalpha(element)) {
//            int weight = what_element_is_it(element);
//            int multiplier = 1;
//
//            // 숫자가 바로 뒤에 있으면 그 숫자만큼 곱함
//            if (i + 1 < n && isdecimal(a_chemical_formula[i + 1])) {
//                multiplier = a_chemical_formula[i + 1] - '0';
//                i++; // 숫자를 처리했으므로 인덱스를 하나 증가
//            }
//
//            molecular_weight += weight * multiplier;
//        }
//    }
//    return molecular_weight;
//}
//
//int main() {
//    cin.tie(nullptr);
//    ios::sync_with_stdio(false);
//    
//    string chemical_formula;
//    cin >> chemical_formula;
//    
//    vector<string> divided_elements;
//    
//    remove_first_parenthesis(chemical_formula);
//    packaging_elements(divided_elements, chemical_formula);
//    print(divided_elements);
//    
////    int sum_of_molecular = 0;
////    for (int i = 0; i < size(divided_elements); ++i) {
////        if (divided_elements[i].size() == 1) {
////            if (!isdecimal(divided_elements[i][0])) {
////                int weight = stoi(divided_elements[i]);
////                sum_of_molecular += find_molecular_weight(divided_elements[i]) * (weight-1);
////            }
////        }
////        else{
////            sum_of_molecular += find_molecular_weight(divided_elements[i]);
////        }
////    }
////    
////    sum_of_molecular *= overall_weight;
////    cout << sum_of_molecular << "\n";
//    
//    int sum_of_molecular = 0;
//    // 각 원소에 대해 분자량 계산
//    for (const auto &element : divided_elements) {
//        sum_of_molecular += find_molecular_weight(element);
//    }
//        
//    // 가중치를 적용한 최종 분자량 출력
//    sum_of_molecular *= overall_weight;
//    cout << sum_of_molecular << "\n";
//    return 0;
//}

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// 원자들의 원자량을 미리 정의
unordered_map<char, int> atomWeight = {
    {'H', 1},
    {'C', 12},
    {'O', 16}
};

int calculateMolecularWeight(const string& formula) {
    stack<int> st;
    int totalWeight = 0;

    for (size_t i = 0; i < formula.size(); ++i) {
        char ch = formula[i];

        if (atomWeight.find(ch) != atomWeight.end()) {
            // 원자라면 스택에 그 원자의 원자량을 푸시
            st.push(atomWeight[ch]);
        } else if (ch == '(') {
            // 여는 괄호는 -1로 표시
            st.push(-1);
        } else if (ch == ')') {
            // 닫는 괄호를 만나면 괄호 안의 원자량을 합산
            int sum = 0;
            while (!st.empty() && st.top() != -1) {
                sum += st.top();
                st.pop();
            }
            st.pop(); // 여는 괄호 제거
            st.push(sum); // 괄호 안의 합을 다시 스택에 푸시
        } else if (isdigit(ch)) {
            // 숫자를 만나면 바로 앞의 원자량이나 괄호에 곱한다
            int multiplier = ch - '0';
            int top = st.top();
            st.pop();
            st.push(top * multiplier);
        }
    }

    // 스택에 남은 원자량을 모두 더함
    while (!st.empty()) {
        totalWeight += st.top();
        st.pop();
    }

    return totalWeight;
}

int main() {
    string formula;
    cin >> formula;

    int result = calculateMolecularWeight(formula);
    cout << result << endl;

    return 0;
}

//자료구조 배우고 다시보자
