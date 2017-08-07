#include "bt.h"

void BT::printVec(vector<TreeNode*>& vec)
{
	for(const auto& v:vec)
		printf("%d ", v->val);
	printf("\n");
}

bool BT::insert(int val)
{
	size += 1;
	if(!root)
	{
		root = new TreeNode(val);
		return true;
	}

	deque<TreeNode*> q;

	q.push_back(root);
	while(!q.empty())
	{
		TreeNode *cur = q.front();
		q.pop_front();


		if(cur->left)
			q.push_back(cur->left);
		else
		{
			cur->left = new TreeNode(val);
			return true;
		}

		if(cur->right)
			q.push_back(cur->right);
		else
		{
			cur->right = new TreeNode(val);
			return true;
		}
	}

	return false;
}

void BT::dfsPrint(TreeNode *node, int level, vector<string>& lines, bool isleft)
{
	if(!node)	return;

	if(lines.size() < (1+level*2))
	{
		if(isleft)
			lines.push_back(to_string(node->val));
		else
			lines.push_back("    " + to_string(node->val));
	}
	else
	{
		if(isleft)
			lines[level*2] += to_string(node->val);
		else
			lines[level*2] += "   " + to_string(node->val);
	}

	if(node->left)
	{
		for(int i = 0; i <= level*2; ++i)
			lines[i] = "  " + lines[i];
		if(lines.size() < (2+level*2))
			lines.push_back(string(" /"));
		else
			lines[level*2+1] += "  /";
		
		dfsPrint(node->left, level+1, lines, true);
	}
	else if(node->right)
	{
		for(int i = 0; i <= level*2; ++i)
			lines[i] = "  " + lines[i];
		if(lines.size() < (2+level*2))
			lines.push_back(string("  "));
		else
			lines[level*2+1] += "   ";
	}

	
	if(node->right)
	{
		if(lines.size() < (2+level*2))
			lines.push_back(string(" \\"));
		else
			lines[level*2+1] += " \\";
		dfsPrint(node->right, level+1, lines, false);
	}
}

void BT::prettyPrint()
{
	vector<string> lines;
	dfsPrint(root, 0, lines, true);	
	
	for(size_t i = 0; i < lines.size(); ++i)
		printf("%s\n", lines[i].c_str());	
}

void BT::print()
{
	if(!root)	return;

	deque<TreeNode*> q;
	q.push_back(root);
	while(!q.empty())
	{
		size_t levelnodes = q.size();
		for(size_t i = 0; i < levelnodes; ++i)
		{
			TreeNode *cur = q.front();
			printf("%d ", cur->val);
			q.pop_front();
		
			if(cur->left)
				q.push_back(cur->left);
			if(cur->right)
				q.push_back(cur->right);
		}
		printf("\n");
	}
}

