#include<stdio.h>


//给定N个三维坐标点(包含整形x, y, z)，找到位于同一条直线上点的最大个数
#include<iostream>
#include<time.h>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct point {
	int x, y, z;
	point(int x, int y, int z) :x(x), y(y), z(z) {}
	bool operator==(const point& pt)const {
		return x == pt.x && y == pt.y &&z == pt.z;
	}
};
struct line {
	float kx, ky;//kx=dx/dz,ky=dy/dz
	bool bz;//dz==0
	bool operator==(const line& l)const {
		return kx == l.kx && ky == l.ky && bz == l.bz;
	}
	bool operator<(const line& l)const {
		return kx < l.kx || (kx == l.kx && ky < l.ky);
	}
};
namespace std {
	template<>
	struct hash<line> {
		size_t operator()(const line& l)const {
			size_t hash1 = 11111111;
			size_t hash2 = 4444;
			size_t hash3 = 89898989;
			return (size_t)(l.kx*hash1) + (size_t)(l.ky*hash2) + hash3 * (int)l.bz;
		}
	};
}
int maxpoints(vector<point> points) {
	int num = 0;
	for (size_t i = 0; i < points.size(); i++) {
		int same = 0;
		int count = 0;
		unordered_map<line, int>map;
		for (size_t j = i + 1; j < points.size(); j++) {
			auto&p1 = points[i];
			auto&p2 = points[j];
			line l;
			if (p1 == p2) { same++; continue; }
			int dz = p2.z - p1.z;
			if (dz == 0) { l.bz = true; l.kx = l.ky = 0; }
			else {
				l.bz = false;
				l.kx = (float)(p2.x - p1.x) / dz;
				l.ky = (float)(p2.y - p1.y) / dz;
			}
			int count1;
			if (map.find(l) == map.end())
				count1 = map[l] = 1;
			else
				count1 = ++map[l];
			count = max(count, count1);
		}
		num = max(count + same + 1, num);
	}
	return num;
}
int main() {
	int n;
	cin >> n;
	vector<point> points;
	point p(0, 0, 0);
	for (int i = 0; i < n; i++) {
		cin >> p.x >> p.y >> p.z;
		points.push_back(p);
	}
	cout << maxpoints(points) << endl;
	return 0;
}