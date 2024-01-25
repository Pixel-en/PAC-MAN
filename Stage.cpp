#include "Stage.h"
#include "Engine/Model.h"
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>



Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hFloor_(-1),hWall_(-1)
{
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Model\\Floor.fbx");
	assert(hFloor_ >= 0);

	hWall_ = Model::Load("Model\\Wall.fbx");
	assert(hWall_ >= 0);

	std::ifstream inputfile;
	inputfile.open("Map.csv", std::ios::in);
	if (inputfile.fail())
		exit(0);

	std::string data;
	
	std::vector<std::string> temp;

	while (std::getline(inputfile,data)) {
		temp.push_back(data);
	}

	for (int i = 0; i < temp.size(); i++) {
		std::stringstream ss{ temp[i] };
		std::string temp2;
		std::vector<int> itmp;
		while (std::getline(ss, temp2, ',')) {
			std::stringstream sstmp{ temp2 };
			int temp3;
			sstmp >> temp3;
			itmp.push_back(temp3);
		}
		map.push_back(itmp);
	}


	inputfile.close();

}

void Stage::Update()
{
}

void Stage::Draw()
{
#if 0
	for (int i = -7; i <= 7; i++) {
		for (int j = -7; j <= 7; j++) {
			//•Ç‚Ì•\Ž¦
			if (i == -7 || i == 7 || j == -7 || j == 7) {
				Transform wallTrans;
				wallTrans.position_ = { (float)i,0,(float)j };
				Model::SetTransform(hWall_, wallTrans);
				Model::Draw(hWall_);
			}
			//°‚Ì•\Ž¦
			else {
				Transform floorTrans;
				floorTrans.position_ = { (float)i,0,(float)j };
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}
#endif


	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			Transform trans;
			trans.position_ = { (float)x - 7.0f,0,7.0f - (float)y };
			if (map[y][x] == 1) {
				Model::SetTransform(hWall_, trans);
				Model::Draw(hWall_);
			}
			else if (map[y][x] == 0) {
				Model::SetTransform(hFloor_, trans);
				Model::Draw(hFloor_);
			}
		}
	}

}

void Stage::Release()
{
}
