bool compare(const string &a, const string &b) {
    if (a.size() == b.size()) {
        if (sum_of_numbers(a) == sum_of_numbers(b)) {
            return a < b;
        }
        else {
            return sum_of_numbers(a) < sum_of_numbers(b);
        }
    }
    else {
        return a.size() < b.size();
    }
}

struct ComparePair {
    bool operator()(const std::pair<int,int>& a,
                    const std::pair<int,int>& b) const {

        return a.first > b.first;
    }
};
