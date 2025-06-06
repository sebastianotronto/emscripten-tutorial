import Primes from "./build/primes.mjs";

var primes = await Primes();
const logPtr = primes.addFunction((cstr) => {
	const str = primes.UTF8ToString(cstr);

	console.log(str);
	postMessage({ message: str });
}, "vp");

onmessage = (e) => {
	const count = primes._primes_in_range(e.data.a, e.data.b, logPtr);
	postMessage({ message: "There are " + count + " primes between " +
		e.data.a + " and " + e.data.b });
};
