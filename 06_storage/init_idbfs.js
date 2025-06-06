Module['preRun'] = [
	async () => {
		const dir = "/assets";

		FS.mkdir(dir);
		FS.mount(IDBFS, { autoPersist: true }, dir);

		Module.fileSystemLoaded = new Promise((resolve, reject) => {
			FS.syncfs(true, (err) => {
				if (err) reject(err);
				else resolve(true);
			});
		});

	}
];
