import MyLibrary from "./build/library.mjs";

var myLibraryInstance = await MyLibrary();

const result = myLibraryInstance._multiply(6, 7);
console.log("The answer is " + result);
