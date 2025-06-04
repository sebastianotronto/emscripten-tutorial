import MyLibrary from "./build/library.mjs";

var myLibraryInstance = await MyLibrary();

var aInput = document.getElementById("aInput");
var bInput = document.getElementById("bInput");
var button = document.getElementById("goButton");
var resultText = document.getElementById("resultText");

button.addEventListener("click", () => {
	var a = Number(aInput.value);
	var b = Number(bInput.value);
	resultText.innerText = myLibraryInstance._multiply(a, b);
});
