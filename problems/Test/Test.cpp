﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//int maxEnvelopes(vector<vector<int>>& envelopes) {
//	int size = envelopes.size();
//	if (size <= 1) return size;
//	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
//		return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
//	});
//	int ans = 0;
//	vector<int> buf(size, INT_MAX);
//	for (auto& env : envelopes) {
//		auto it = lower_bound(buf.begin(), buf.end(), env[1]);
//		*it = env[1];
//		ans = max(ans, int(it - buf.begin()) + 1);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
	if (envelopes.size() <= 1) return envelopes.size();

	sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
	{
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	vector<int> vec;
	for (int i = 0; i < envelopes.size(); i++)
	{
		int h = envelopes[i][1];
		if (vec.empty() || h > vec.back())
		{
			vec.push_back(h);
		}

		for (int j = 0; j < vec.size(); j++)
		{
			if (h <= vec[j])
			{
				vec[j] = h;
				break;
			}
		}
	}

	return vec.size();
}



int main()
{
	vector<vector<vector<int>>> TESTS;
	//vector<vector<int>> K;
	vector<int> ANSWERS;

	TESTS.push_back(StringToVectorVectorInt("[[5,4],[6,4],[6,7],[2,3]]"));
	ANSWERS.push_back(3);

	TESTS.push_back(StringToVectorVectorInt("[[46,89],[50,53],[52,68],[72,45],[77,81]]"));
	ANSWERS.push_back(3);

	TESTS.push_back(StringToVectorVectorInt("[[4,5],[4,6],[6,7],[2,3],[1,1]]"));
	ANSWERS.push_back(4);

	TESTS.push_back(StringToVectorVectorInt("[[8,3],[3,20],[15,5],[11,2],[19,6],[9,18],[1,19],[13,3],[14,20],[6,7]]"));
	ANSWERS.push_back(4);

	TESTS.push_back(StringToVectorVectorInt("[[15,8],[2,20],[2,14],[4,17],[8,19],[8,9],[5,7],[11,19],[8,11],[13,11],[2,13],[11,19],[8,11],[13,11],[2,13],[11,19],[16,1],[18,13],[14,17],[18,19]]"));
	ANSWERS.push_back(5);

	TESTS.push_back(StringToVectorVectorInt("[[856,533],[583,772],[980,524],[203,666],[987,151],[274,802],[982,85],[359,160],[58,823],[512,381],[796,655],[341,427],[145,114],[76,306],[760,929],[836,751],[922,678],[128,317],[185,953],[115,845],[829,991],[93,694],[317,434],[818,571],[352,638],[926,780],[819,995],[54,69],[191,392],[377,180],[669,952],[588,920],[335,316],[48,769],[188,661],[916,933],[674,308],[356,556],[350,249],[686,851],[600,178],[849,439],[597,181],[80,382],[647,105],[4,836],[901,907],[595,347],[214,335],[956,382],[77,979],[489,365],[80,220],[859,270],[676,665],[636,46],[906,457],[522,769],[2,758],[206,586],[444,904],[912,370],[64,871],[59,409],[599,238],[437,58],[309,767],[258,440],[922,369],[848,650],[478,76],[84,704],[314,207],[138,823],[994,764],[604,595],[537,876],[877,253],[945,185],[623,497],[968,633],[172,705],[577,388],[819,763],[409,905],[275,532],[729,593],[547,226],[445,495],[398,544],[243,500],[308,24],[652,452],[93,885],[75,884],[243,113],[600,555],[756,596],[892,762],[402,653],[916,975],[770,220],[455,579],[889,68],[306,899],[567,290],[809,653],[92,329],[370,861],[632,754],[321,689],[190,812],[88,701],[79,310],[917,91],[751,480],[750,39],[781,978],[778,912],[946,559],[529,621],[55,295],[473,748],[646,854],[930,913],[116,734],[647,812],[426,172],[122,14],[522,843],[88,308],[719,602],[712,928],[303,890],[973,886],[276,354],[660,720],[708,387],[776,605],[653,815],[448,285],[549,959],[139,365],[74,952],[372,424],[642,504],[361,901],[620,612],[313,301],[397,225],[446,716],[17,361],[160,812],[171,529],[180,482],[454,600],[228,872],[204,492],[607,889],[86,79],[494,78],[442,404],[462,127],[935,402],[509,649],[458,941],[219,444],[306,57],[674,617],[79,652],[73,735],[900,756],[649,294],[982,754],[521,439],[356,265],[240,533],[865,44],[744,379],[97,454],[65,480],[544,191],[18,191],[503,38],[696,658],[61,884],[793,984],[383,364],[280,467],[888,662],[133,643],[365,512],[610,975],[98,584],[40,177],[548,102],[80,98],[986,951],[264,258],[583,734],[353,322],[427,551],[80,660],[273,609],[980,871],[739,802],[366,836],[55,509],[889,720],[857,661],[48,489],[119,26],[31,180],[472,673],[960,951],[383,500],[928,351],[848,705],[969,766],[311,714],[861,230],[34,596],[38,642],[1,955],[698,846],[784,791],[760,344],[677,239],[969,191],[539,644],[470,418],[289,357],[269,446],[668,245],[293,719],[937,103],[575,297],[874,656],[714,257],[934,396],[109,904],[89,635],[374,545],[316,587],[158,121],[901,969],[284,564],[666,568],[993,409],[370,637],[443,694],[576,160],[262,357],[590,729],[194,976],[743,376],[348,80],[669,527],[338,953],[236,785],[144,460],[438,457],[517,951],[545,647],[158,556],[905,591],[793,609],[571,643],[9,850],[581,490],[804,394],[635,483],[457,30],[42,621],[65,137],[424,864],[536,455],[59,492],[645,734],[892,571],[762,593],[608,384],[558,257],[692,420],[973,203],[531,51],[349,861],[804,649],[3,611],[6,468],[298,568],[651,767],[251,142],[173,974],[117,728],[326,562],[894,288],[814,555],[420,771],[20,775],[445,247],[243,592],[186,173],[101,800],[590,876],[515,534],[73,540],[333,215],[902,394],[640,787],[596,298],[984,712],[307,378],[540,646],[473,743],[340,387],[756,217],[139,493],[9,742],[195,25],[763,823],[451,693],[24,298],[645,595],[224,770],[976,41],[832,78],[599,705],[487,734],[818,134],[225,431],[380,566],[395,680],[294,320],[915,201],[553,480],[318,42],[627,94],[164,959],[92,715],[588,689],[734,983],[976,334],[846,573],[676,521],[449,69],[745,810],[961,722],[416,409],[135,406],[234,357],[873,61],[20,521],[525,31],[659,688],[424,554],[203,315],[16,240],[288,273],[281,623],[651,659],[939,32],[732,373],[778,728],[340,432],[335,80],[33,835],[835,651],[317,156],[284,119],[543,159],[719,820],[961,424],[88,178],[621,146],[594,649],[659,433],[527,441],[118,160],[92,217],[489,38],[18,359],[833,136],[470,897],[106,123],[831,674],[181,191],[892,780],[377,779],[608,618],[618,423],[180,323],[390,803],[562,412],[107,905],[902,281],[718,540],[16,966],[678,455],[597,135],[840,7],[886,45],[719,937],[890,173]]"));
	ANSWERS.push_back(35);


	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = maxEnvelopes(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}


// int main()
// {
// 	vector<vector<int>> TESTS;
// 	//vector<int> K;
// 	vector<bool> ANSWERS;
// 
// 	//TESTS.push_back(StringToVectorInt("[1,2,3,4,5]"));
// 	//ANSWERS.push_back(true);
// 
// 	//TESTS.push_back(StringToVectorInt("[5,4,3,2,1]"));
// 	//ANSWERS.push_back(false);
// 
// 	//TESTS.push_back(StringToVectorInt("[9,7,8,5,6,3,4,1,2]"));
// 	//ANSWERS.push_back(false);
// 
// 	//TESTS.push_back(StringToVectorInt("[9,7,8,5,6,1,4,2,3]"));
// 	//ANSWERS.push_back(true);
// 
// 	//TESTS.push_back(StringToVectorInt("[3,9,8,5,2,1,2,3,4]"));
// 	//ANSWERS.push_back(true);
// 
// 	//TESTS.push_back(StringToVectorInt("[5,1,5,5,2,5,4]"));
// 	//ANSWERS.push_back(true);
// 
// 	TESTS.push_back(StringToVectorInt("[1,1,-2,6]"));
// 	ANSWERS.push_back(false);
// 
// 	for (int j = 0; j < TESTS.size(); j++)
// 	{
// 		cout << endl << "/////////////////////////////" << endl;
// 		//auto ans = setZeroes(TESTS[j]);
// 		printVectorInt(TESTS[j]);
// 		bool ans = increasingTriplet(TESTS[j]);
// 		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[j]) << endl;
// 	}
// }


//////////////////////////////////////////////////////////////////////////
// 二维数组
//int main()
//{
//	vector<vector<vector<int>>> TESTS;
//	//vector<int> K;
//	vector<vector<vector<int>>> ANSWERS;
//
//	TESTS.push_back(StringToVectorVectorInt("[[1, 0]]"));
//	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0]]"));
//
//	TESTS.push_back(StringToVectorVectorInt("[[1, 0, 3]]"));
//	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0, 0]]"));
//
//	TESTS.push_back(StringToVectorVectorInt("[[1, 1, 1],[1, 0, 1],[1, 1, 1]]"));
//	ANSWERS.push_back(StringToVectorVectorInt("[[1, 0, 1],[0, 0, 0],[1, 0, 1]]"));
//
//	TESTS.push_back(StringToVectorVectorInt("[[0, 1, 2, 0],[3, 4, 5, 2],[1, 3, 1, 5]]"));
//	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0, 0, 0],[0, 4, 5, 0],[0, 3, 1, 0]]"));
//
//	for (int j = 0; j < TESTS.size(); j++)
//	{
//		cout << endl << "/////////////////////////////" << endl;
//		//auto ans = setZeroes(TESTS[j]);
//		printVectorVectorInt(TESTS[j]);
//		setZeroes(TESTS[j]);
//		cout << checkAnswer<decltype(TESTS[j])>(TESTS[j], ANSWERS[j]) << endl;
//	}
//}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//int main()
//{
//	vector<TreeNode *> N;
//	vector<int> K;
//	vector<bool> A;
//
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
//	//K.push_back(3);
//	A.push_back(true);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	for (int j = 0; j < N.size(); j++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		cout << N[j] << endl;
//		//DrawTreeNode(N[j]);
//
//		bool ans = isBalanced(N[j]);
//		cout << checkAnswer<bool>(ans, A[j]) << endl;
//		//DrawTreeNode(ans);
//
//	}
//}


//////////////////////////////////////////////////////////////////////////
// List Node
//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = nullptr;
//	StringToListNode(&pHead, "[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto p : lists)
//	{
//		PrintLinkList(p);
//		pHead = sortList(p);
//		PrintLinkList(pHead);
//		cout << endl;
//	}
//}


