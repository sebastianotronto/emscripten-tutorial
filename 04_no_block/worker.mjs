import Primes from "./build/primes.mjs";

var primes = await Primes();

onmessage = (e) => {
	const count = primes._primes_in_range(e.data.a, e.data.b);
	postMessage({ result: count, a: e.data.a, b: e.data.b });
};
