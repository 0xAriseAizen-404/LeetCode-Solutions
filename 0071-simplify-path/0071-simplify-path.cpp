class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components;
        string component;
        int i = 0, n = path.size();
        while (i < n) {
            while (i < n && path[i] == '/') i++;
            component = "";
            while (i < n && path[i] != '/') component += path[i++];
            if (component == "" || component == ".") {
                continue;  
            }
            if (component == "..") {
                if (!components.empty()) components.pop_back();  
            } else {
                components.push_back(component);  
            }
        }
        string res = "/";
        for (int j = 0; j < components.size(); ++j) {
            if (j > 0) res += "/";
            res += components[j];
        }
        return res;
    }
};
