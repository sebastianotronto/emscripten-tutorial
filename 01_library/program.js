var library = require("./build/library.js");

library.onRuntimeInitialized = () => {
	const result = library._multiply(6, 7);
	console.log("The answer is " + result);
};
