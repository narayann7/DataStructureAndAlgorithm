package main

import (
	"log"
	"os"
)

func main() {
	// first remove the public and src folder which includes default files
	os.RemoveAll("public")
	os.RemoveAll("src")

	MakePublicFolder()
	MakeSrcFolder()

}
func MyErrorCheck(err error) {
	if err != nil {
		log.Println(err)
		panic(err)
	}
}

func MakePublicFolder() {
	// create the public folder
	os.Mkdir("public", 0755)

	//get path
	path, _ := os.Getwd()
	os.Chdir(path + "/public")

	// create index.html file
	createNewFileAndAddContent("index.html")
	//change path root folder
	os.Chdir(path)
}

func MakeSrcFolder() {

	// make src folder
	os.Mkdir("src", 0775)
	path, err := os.Getwd()
	MyErrorCheck(err)
	os.Chdir(path + "/src")

	//create App.css file
	createNewFileAndAddContent("App.css")
	//create App.js file
	createNewFileAndAddContent("App.js")
	//create index.js file
	createNewFileAndAddContent("index.js")

	//change path root folder
	os.Chdir(path)

}

func createNewFileAndAddContent(fileName string) {

	os.Create(fileName)
	file, err := os.OpenFile(fileName, os.O_APPEND|os.O_WRONLY, 0644)
	MyErrorCheck(err)
	defer file.Close()

	_, err = file.WriteString(getContent(fileName))
	MyErrorCheck(err)

}

func getContent(fileName string) string {

	content := map[string]string{
		"App.css": `* {
			padding: 0;
			margin: 0;
			scroll-behavior: smooth;
			box-sizing: border-box;
		}
		
		#root {
			padding: 0px;
			margin: 0px;
		}
		`,

		"index.html": `<!DOCTYPE html>
		<html lang="en">
		<head>
		<meta charset="UTF-8" />
		<meta http-equiv="X-UA-Compatible" content="IE=edge" />
		<meta name="viewport" content="width=device-width, initial-scale=1.0" />
		<title>Title</title>
		</head>
		<body>
		<div id="root"></div>
		</body>
		</html>
		`,
		"App.js": `import React from "react";
		import "./App.css";

		function App() {
			return (
				<div
				style={{
					display: "flex",
					justifyContent: "center",
					alignItems: "center",
					height: "100vh",
					width: "100vw",
				}}
				>
				Happy coding!
				</div>
			);
		}

		export default App;
		`,
		"index.js": `import React from "react";
		import ReactDOM from "react-dom/client";
		import App from "./App";
		const root = ReactDOM.createRoot(document.querySelector("#root"));
		root.render(
			<React.StrictMode>
			<App />
			</React.StrictMode>
		);

		`,
	}

	return content[fileName]

}
