import Primes from "./build/primes.mjs"

var primes = await Primes();
const logPtr = primes.addFunction((cstr) => {
	console.log(primes.UTF8ToString(cstr));
}, 'vp');

const a = 1;
const b = 10000000;
const count = primes._primes_in_range(a, b, logPtr);
console.log("There are " + count + " primes between " + a + " and " + b);
