// @Thomas C
/*sample input: 
add {first:John,last:Smith,id:12345,keyex:valueex}
add {first:James,last:Smith,id:12346,keyex:valueex}
add {first:Jim,last:Smith,id:12347,keyex:valueex}

... 100,000 more records ...

delete {first:John}
get {id:12346}
*/

#include"ArgumentManager.h"
#include<iostream>
#include<string>
#include<set>
#include<unordered_map>
#include<map>
#include<sstream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

// CLEAN line: "{a:1,b:2,c:3}" --> " a:1 b:2 c:3 "
void clean(string& line) {
	for (auto& c : line) {
		if (c == '{' || c == '}' || c == ',') {
			c = ' ';
		}
	}
}

// ofs intersections from get
void output_intersections(ofstream& ofs, const set<unsigned long long>& intersect, map<unsigned long long, vector<string>>& id_records) {
	for (auto& id : intersect) {
		ofs << "{";
		auto& record = id_records[id];
		for (int i = 0; i < record.size(); ++i) {
			auto& att = record.at(i);
			ofs << att;
			if (i != record.size() - 1) ofs << ",";
		}
		ofs << "}\n";	
	}
	ofs << "\n";
}

// Clean Line --> Vec of Atttributes
vector<string> getAtts(string& clean_line) {
	vector<string> atts;
	string attribute;
	stringstream testing(clean_line);
	while (testing >> attribute) {
		atts.push_back(attribute);
	}
	return atts;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Usage: ./associativecontainers input=in1.txt output=out1.txt" << std::endl;
		return -1;
	}
	ArgumentManager am(argc, argv);
	const std::string input = am.get("input");
	const std::string output = am.get("output");
	unordered_map<string, set<unsigned long long>> umap;
	map<unsigned long long, vector<string>> bst;
	ifstream ifs(input);
	ofstream ofs(output);
	string op, line;
	size_t id = 0;
	while (ifs >> op >> line) {
		clean(line);
		auto atts = getAtts(line);
		if (op == "add") { // begin ADD
			for (string& att : atts) {
				umap[att].insert(id);
			}
			bst[id] = atts;
			++id;
		} // end ADD
		else if (op == "get") { // begin GET
			set<unsigned long long> result;

			result = umap[atts[0]];
			set<unsigned long long> result2;
			for (int i = 1; i < atts.size(); i++) {
				result2.clear();
				set_intersection(result.begin(), result.end(), umap[atts[i]].begin(), umap[atts[i]].end(), inserter(result2, result2.begin()));
				result = result2;
			}
			output_intersections(ofs,result,bst);
		} // end GET
		else if (op == "delete") { // delete
			set<unsigned long long> result;
			result = umap[atts[0]];
			set<unsigned long long> result2;
			for (int i = 1; i < atts.size(); i++) {
				result2.clear();
				set_intersection(result.begin(), result.end(), umap[atts[i]].begin(), umap[atts[i]].end(), inserter(result2, result2.begin()));
				result = result2;
			}
			// remove index from bst
			for (auto i : result) {
				bst.erase(i);
			}
			// remove index from umap
			for (int i = 0; i < atts.size(); i++) {
				for (auto a : result) {
					umap[atts[i]].erase(a);
				}
			}
		} // end delete
	} // end while stringstream
	return 0;
}
