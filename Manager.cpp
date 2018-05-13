#include "Manager.h"

<<<<<<< HEAD
GameManager::GameManager() : text(FontFile), box(DarkStormy, lightSky), Shader("Light.vs", "Light.fs"), play(false), real_world_(phys_world()) {
=======
GameManager::GameManager() : text(FontFile), box(DarkStormy, lightSky), Shader("Light.vs", "Light.fs"), play(false),
real_world_(phys_world()){
>>>>>>> 37cc3c4c7be7c585ca74790fd9c7fd961e34cab2
	LoadInfoAboutLevels();
}

void GameManager::LoadInfoAboutLevels() {
	std::ifstream fin(LoadFile);
	if (!fin.is_open()) {
		throw GameException(__LINE__, __func__, "error open file Load.file");
	}
	string name_buf = "";
	string path_buf = "";
#if DEBUG_MANAGER
	print(string("\ntry to read: ") + LoadFile);
#endif
	while (!fin.eof()) {
		getStringFromFile(fin, name_buf);
		if (name_buf == "end_of_file" || name_buf == "null") {
			break;
		}
		getStringFromFile(fin, path_buf);
		if (path_buf == "end_of_file" || name_buf == "null") {
			throw GameException(__LINE__, __func__, "error format Load.file");
		}
		Levels.push_back(Level(name_buf, path_buf));
	}
	if (Levels.size() == 0) {
		throw GameException(__LINE__, __func__, "LoadFile.file is empty");
	}
#if DEBUG_MANAGER
	print("success\n");
#endif
}

void GameManager::LoadInfoAboutModels(uint levelNumber) {
	string path_tmp = Levels.at(levelNumber).pathLoader_;
	std::ifstream fin(path_tmp);
	if (!fin.is_open()) {
		throw GameException(__LINE__, __func__, "error open file level.file");
	}

#if DEBUG_MANAGER
	print(string("try to read: ") + path);
#endif
<<<<<<< HEAD
	int type;
	vec3 place;
	vec3 quat;
	string path;
	vec3 scale;
	double mass;
	vec3 box;
	while (!fin.eof()) {
		GameModel* NewModel = nullptr;
		string strbuf = "";
		getStringFromFile(fin, strbuf);
		if (strbuf == "null") {
			throw GameException(__LINE__, __func__, "error level.path");
		}
		if (strbuf == "end_of_file") {
			break;
		}
		if (strbuf != "type") {
			throw GameException(__LINE__, __func__, "error level.path");
		}

		getStringFromFile(fin, type);
		if (strbuf == "null" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error level.path");
		}

		getStringFromFile(fin, strbuf);
		if (strbuf != "path" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error type");
		}
		getStringFromFile(fin, path);

		getStringFromFile(fin, strbuf);
		if (strbuf != "place" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error place");
		}
		getStringFromFile(fin, place);

		getStringFromFile(fin, strbuf);
		if (strbuf != "quat" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error quat");
		}
		getStringFromFile(fin, quat);

		getStringFromFile(fin, strbuf);
		if (strbuf != "scale" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error scale");
		}
		getStringFromFile(fin, scale);

		getStringFromFile(fin, strbuf);
		if (strbuf != "mass" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error mass");
		}
		getStringFromFile(fin, mass);

		getStringFromFile(fin, strbuf);
		if (strbuf != "box" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error box");
		}
=======
	int type;
	vec3 place;
	vec3 quat;
	string path;
	vec3 scale;
	double mass;
	vec3 box;
	while (!fin.eof()) {
		GameModel* NewModel = nullptr;
		string strbuf = "";
		getStringFromFile(fin, strbuf);
		if (strbuf == "null") {
			throw GameException(__LINE__, __func__, "error level.path");
		}
		if (strbuf == "end_of_file") {
			break;
		}
		if (strbuf != "type") {
			throw GameException(__LINE__, __func__, "error level.path");
		}

		getStringFromFile(fin, type);
		if (strbuf == "null" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error level.path");
		}

		getStringFromFile(fin, strbuf);
		if (strbuf != "path" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error type");
		}
		getStringFromFile(fin, path);

		getStringFromFile(fin, strbuf);
		if (strbuf != "place" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error place");
		}
		getStringFromFile(fin, place);

		getStringFromFile(fin, strbuf);
		if (strbuf != "quat" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error quat");
		}
		getStringFromFile(fin, quat);

		getStringFromFile(fin, strbuf);
		if (strbuf != "scale" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error scale");
		}
		getStringFromFile(fin, scale);

		getStringFromFile(fin, strbuf);
		if (strbuf != "mass" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error mass");
		}
		getStringFromFile(fin, mass);

		getStringFromFile(fin, strbuf);
		if (strbuf != "box" || strbuf == "end_of_file") {
			throw GameException(__LINE__, __func__, "error box");
		}
>>>>>>> 37cc3c4c7be7c585ca74790fd9c7fd961e34cab2
		getStringFromFile(fin, box);
		if (!NewModel) {
			switch (type) {
			case GAMEMODEL:
<<<<<<< HEAD
				NewModel = new GameModel(real_world_, type, place, quat, path, scale, mass, box, 32.0f, true);
				break;
			case ANIMATION:
				NewModel = new AnimatedModel(real_world_, type, place, quat, path, scale, mass, box, 32.0f, true);
				break;
			case STRUCTURE:
				NewModel = new Structure(real_world_, type, place, quat, path, scale, mass, box, 16.0f, true);
				break;
			case STREETLAMP:
				NewModel = new StreetLamp(real_world_, type, place, quat, path, scale, mass, box, 32.0f, true, true);
				//Light.PointLights.push_back(PointLight(NewModel, ))
			default:
				NewModel = new GameModel(real_world_, type, place, quat, path, scale, mass, box, 32.0f, true);
=======
				NewModel = new GameModel( real_world_, type, place, quat, path, scale, mass, box, 32.0f, true);
				break;
			case ANIMATION:
				NewModel = new AnimatedModel( real_world_, type, place, quat, path, scale, mass, box,32.0f, true );
				break;
			case STRUCTURE:
				NewModel = new Structure( real_world_, type, place, quat, path, scale, mass, box, 16.0f, true);
				break;
			case STREETLAMP:
				NewModel = new StreetLamp( real_world_, type, place, quat, path, scale, mass, box, 32.0f, true, true);
				//Light.PointLights.push_back(PointLight(NewModel, ))
			default:
				NewModel = new GameModel( real_world_, type, place, quat, path, scale, mass, box, 32.0f, true);
>>>>>>> 37cc3c4c7be7c585ca74790fd9c7fd961e34cab2
			}
			NewModel->type_ = type;
		}
		else {
			throw GameException(__LINE__, __func__, "Error wrong type of class");
		}
#if DEBUG_MANAGER
		NewModel->PrintModel();
#endif
		AllModels.push_back(NewModel);
	}
	if (AllModels.size() == 0) {
		throw GameException(__LINE__, __func__, "level.file is empty");
	}
	LoadModels();
#if DEBUG_MANAGER
	print("success");
#endif
}

void GameManager::LoadModels() {
	bool ModelLoaded = false;
	for (uint i = 0; i < AllModels.size(); i++) {
		ModelLoaded = false;
		for (auto& it : LoadedModels) {
			if (it.path_ == AllModels[i]->path_ && it.type_ == AllModels[i]->type_) {
				AllModels[i]->CopyModel(AllModels[it.id_]);
				ModelLoaded = true;
			}
		}
		if (!ModelLoaded) {
			LoadedModels.push_back(LoadedModel(AllModels[i]->path_, AllModels[i]->type_, i));
			AllModels[i]->LoadModel();
		}
	}
	for (auto& it : AllModels) {
		it->ClearLoaded();
	}
}

void GameManager::RenderModels(const mat4& projection, const mat4& view, const Camera& camera, float time) {
	Shader.Use();
	Light.SetLight(Shader);
	Shader.setMat4("projection", projection);
	Shader.setMat4("view", view);
	Shader.setVec3("viewPos", camera.Position);
	for (auto& it : AllModels) {
		if (it->draw_) {
			it->SetShaderParameters(Shader);
			it->Draw(Shader);
		}
	}
}

bool GameManager::GameMenu(GLFWwindow* window, const Image& Loading) {
#if DEBUG_MENU
	int levelNumber = ChooseLevel();
#else
	int levelNumber = ChooseLevel(window);
#endif
	if (levelNumber == -1) {
		return false;
	}
	else {
		Loading.RenderImage(true);
		LoadInfoAboutModels(levelNumber);
		play = true;
		return true;
	}
}

void GameManager::RenderWorld(const mat4& projection, const mat4& view, const Camera& camera, float time) {
	real_world_.do_step(time);
	RenderModels(projection, view, camera, time);
	box.RenderBox(camera, projection);
	text.RenderText("HP, MP bullets", 10.0f, (float)WIDTH / 2, 1.0f, vec3(1.0f, 0.0f, 0.0f));
}

void GameManager::ProcessInputInMenu(GLFWwindow* window, uint& key_pressed) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		key_pressed = 1;
		return;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		key_pressed = 3;
		return;
	}
	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
		key_pressed = 2;
		return;
	}
}

void GameManager::EndLevel() {
	SysText.clear();
	AllModels.clear();
	LoadedModels.clear();
}

int GameManager::ChooseLevel(GLFWwindow* window) {
	uint key = 0;
	uint chosen = 1;
	GLdouble deltaTime, currentFrame, lastFrame = 0.0;
	GLdouble accumulator = 0.0;
	Image Menu(MenuImage);
	SysText.clear();

	SysText.push_back(SysStrings("Wastelands of the USSR", (float)HEIGHT / 4.5f, (float)WIDTH / 7 * 6, 0.85f, vec3(0.5f)));
	for (uint i = 0; i < Levels.size(); i++) {
		SysText.push_back(SysStrings(Levels[i].name_, (float)HEIGHT / 6, (float)WIDTH / 14 * (11 - (i + 1)), 0.7f, vec3(0.5f)));
	}

	SysText[chosen].color_ = vec3(1.0f, 0.0f, 0.0f);

	while (!glfwWindowShouldClose(game_window)) {
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		accumulator += deltaTime;
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ProcessInputInMenu(game_window, key);

		if (accumulator > 0.5) {
			accumulator = 0;
			if (key == 3) {
				if (chosen < Levels.size()) {
					SysText[chosen].color_ = vec3(0.5f);
					chosen++;
					SysText[chosen].color_ = vec3(1.0f, 0.0f, 0.0f);
				}
				else {
					SysText[chosen].color_ = vec3(0.5f);
					chosen = 1;
					SysText[chosen].color_ = vec3(1.0f, 0.0f, 0.0f);
				}
			}
			else if (key == 1) {
				if (chosen > 1) {
					SysText[chosen].color_ = vec3(0.5f);
					chosen--;
					SysText[chosen].color_ = vec3(1.0f, 0.0f, 0.0f);
				}
				else {
					SysText[chosen].color_ = vec3(0.5f);
					chosen = Levels.size();
					SysText[chosen].color_ = vec3(1.0f, 0.0f, 0.0f);
				}
			}
			else if (key == 2) {
				return chosen - 1;
			}
			key = 0;
		}

		Menu.RenderImage();
		text.RenderText(SysText);

		glfwSwapBuffers(game_window);
		glfwPollEvents();
	}

	SysText.clear();
	return -1;
}