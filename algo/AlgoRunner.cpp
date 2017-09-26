#include "AlgoRunner.h"

void AlgoRunner::run(char* algoname)
{
	DIR *dir;
	struct dirent *ent;
	
	vector<vector<int>> nums = {{1,2},{2,1}};
	Matrix<int> mat(nums);
	mat.print();

	vector<vector<int>> nums2 = {{3,1},{2,3}};
	Matrix<int> mat2(nums2);
	mat2.print();

	Matrix<int> matres = mat*mat2;
	matres.print();

	mat.print();
	mat2.print();
}
