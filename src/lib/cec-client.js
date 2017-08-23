
const Libcec = require("../../build/Release/cec-client");

const EventEmitter = require("events");

class CecEventEmitter extends EventEmitter {

    constructor() {
        super();
    }

    initialize() {
        this.on("initializing", this.handleInit);

        this.on("test emit", () => {
            console.log("testing emitter");
        })

        this.on("other", (...args) => {
            for (let [index, arg] of args.entries()) {
                console.log(`arg${index}: ${arg}`);
            }
        });
    }

    handleInit() {
        console.log("Initializing...");
    }

}


class CecClient {

    constructor() {
        this.emitter = new CecEventEmitter();
        this.client = new Libcec.Client();

    }

    start() {
        this.emitter.initialize();
        this.client.initialize();
        this.client.addEmitter(this.emitter);
        this.client.testEmit();
        setTimeout(() => {
            this.client.testEmit();
        }, 2000);
        while (1) {}
    }

    on(event, callback) {
        emitter.on(event, callback);
    }

}


module.exports = CecClient;

