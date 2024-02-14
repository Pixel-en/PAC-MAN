#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Collider.h"
#include "Engine/CsvReader.h"
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include "Engine/Camera.h"



bool Stage::IsWall(int _x, int _y)
{
	if (map[_y][_x] == STAGE_OBJ::WALL)
		return true;
	else
		return false;
}

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hFloor_(-1),hWall_(-1)
{
#if 0

	std::ifstream inputfile;
	inputfile.open("Map.csv", std::ios::in);
	if (inputfile.fail())
		exit(0);

	std::string data;

	std::vector<std::string> temp;

	while (std::getline(inputfile, data)) {
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

	stageWidth_ = map[0].size();
	stageHeight_ = map.size();

#endif

#if 1
	CsvReader csv;
	csv.Load("map.csv");


	stageWidth_ = csv.GetWidth();
	stageHeight_ = csv.GetHeight();


	for (int i = 0; i < stageHeight_; i++)
	{
		std::vector<int> sdata(stageWidth_, 0);//stageWidth_ŒÂ‚Ì”z—ñ‚ğ0‚Å‰Šú‰»
		map.push_back(sdata);
	}


	for (int j = 0; j < stageHeight_; j++)
	{
		for (int i = 0; i < stageWidth_; i++)
		{
			map[j][i] = csv.GetValue(i, j);
		}
	}

#endif
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Model\\Floor.fbx");
	assert(hFloor_ >= 0);

	hWall_ = Model::Load("Model\\Wall.fbx");
	assert(hWall_ >= 0);

	Camera::SetPosition({ 6.5, 10, -5 });
	Camera::SetTarget({ 6.5, 0, 5.5 });

}

void Stage::Update()
{
}

void Stage::Draw()
{
#if 0
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
#endif

	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };

	for (int z = 0; z < stageHeight_; z++) {
		for (int x = 0; x < stageWidth_; x++) {
			floorTrans.position_ = { (float)x, 0, (float)(14 - z) };
			//if (x == 0 || z == 0 || x == 14 || z == 14) {
			//	Model::SetTransform(hBlock_, floorTrans);
			//	Model::Draw(hBlock_);
			//}
			//else {
			//	Model::SetTransform(hFloor_, floorTrans);
			//	Model::Draw(hFloor_);
			//}
			if (map[z][x] == 1) {
				Model::SetTransform(hWall_, floorTrans);
				Model::Draw(hWall_);
			}
			else {
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}
}

void Stage::Release()
{
	for (int i = 0; i < stageHeight_; i++)
	{
		map[i].clear();
	}
	map.clear();
}
