/* Copyright (C) hansang.cho
 * Written by hansang.cho <hehpollon@gmail.com>, 2019
 */

let connectServer;

window.onload = function () {
    let conn;
    let msg = document.getElementById("msg");
    let log = document.getElementById("log");
    let host = document.getElementById("host");
    let lineCount = 0;

    $( "#sidebar" ).simplerSidebar( {
        selectors: {
            trigger: "#toggle-sidebar",
            quitter: ".close-sidebar",

        },
        animation: {
            duration: 300,
            easing: "easeOutQuint"
        },
    } );

    connectServer = function(){
        if (window["WebSocket"]) {
            if (conn && conn.readyState !== WebSocket.CLOSED) {
                conn.close();
            }
            conn = new WebSocket(host.value);
            conn.onclose = function (evt) {
                let reason;
                if (event.code === 1000)
                    reason = "Normal closure, meaning that the purpose for which the connection was established has been fulfilled.";
                else if(event.code === 1001)
                    reason = "An endpoint is \"going away\", such as a server going down or a browser having navigated away from a page.";
                else if(event.code === 1002)
                    reason = "An endpoint is terminating the connection due to a protocol error";
                else if(event.code === 1003)
                    reason = "An endpoint is terminating the connection because it has received a type of data it cannot accept (e.g., an endpoint that understands only text data MAY send this if it receives a binary message).";
                else if(event.code === 1004)
                    reason = "Reserved. The specific meaning might be defined in the future.";
                else if(event.code === 1005)
                    reason = "No status code was actually present.";
                else if(event.code === 1006)
                    reason = "The connection was closed abnormally, e.g., without sending or receiving a Close control frame";
                else if(event.code === 1007)
                    reason = "An endpoint is terminating the connection because it has received data within a message that was not consistent with the type of the message (e.g., non-UTF-8 [http://tools.ietf.org/html/rfc3629] data within a text message).";
                else if(event.code === 1008)
                    reason = "An endpoint is terminating the connection because it has received a message that \"violates its policy\". This reason is given either if there is no other sutible reason, or if there is a need to hide specific details about the policy.";
                else if(event.code === 1009)
                    reason = "An endpoint is terminating the connection because it has received a message that is too big for it to process.";
                else if(event.code === 1010) // Note that this status code is not used by the server, because it can fail the WebSocket handshake instead.
                    reason = "An endpoint (client) is terminating the connection because it has expected the server to negotiate one or more extension, but the server didn't return them in the response message of the WebSocket handshake. <br /> Specifically, the extensions that are needed are: " + event.reason;
                else if(event.code === 1011)
                    reason = "A server is terminating the connection because it encountered an unexpected condition that prevented it from fulfilling the request.";
                else if(event.code === 1015)
                    reason = "The connection was closed due to a failure to perform a TLS handshake (e.g., the server certificate can't be verified).";
                else
                    reason = "Unknown reason";

                let item = document.createElement("div");
                item.innerHTML = "<b>connection closed: "+reason+"</b>";
                appendLog(item);
            };
            conn.onmessage = function (evt) {
                    let data = JSON.parse(evt.data).data;
                    if (typeof data !== "undefined") {
                        let messages = "";
                        try {
                            data = JSON.stringify(data, null, 2);
                            messages = data.split('\n');
                            for (let i = 0; i < messages.length; i++) {
                                let item = document.createElement("div");
                                item.innerText = "-> " + messages[i];
                                appendLog(item);
                            }
                        } catch {
                            messages = JSON.stringify(data);
                            let item = document.createElement("div");
                            item.innerText = "-> " + messages;
                            appendLog(item);
                        }
                    }else {
                        let data = JSON.parse(evt.data).broadcast;
                        messages = JSON.stringify(data);
                        let item = document.createElement("div");
                        item.innerText =  "-> " + messages ;
                        appendLog(item, 1);
                    }
            };
            conn.onerror = function (event) {

            };
            conn.onopen = function (evt) {
                let item = document.createElement("div");
                item.innerHTML = "<b>Connection established.</b>";
                appendLog(item);
            };
        } else {
            let item = document.createElement("div");
            item.innerHTML = "<b>Your browser does not support WebSockets.</b>";
            appendLog(item);
        }
    };

    function getTime(){
        let today = new Date();
        let dayNames = ['(일요일)', '(월요일)', '(화요일)', '(수요일)', '(목요일)', '(금요일)', '(토요일)'];
        let year   = today.getFullYear(),
            month  = today.getMonth() + 1,
            date   = today.getDate(),
            hour   = today.getHours(),
            minute = today.getMinutes(),
            second = today.getSeconds(),
            ampm   = hour >= 12 ? 'PM' : 'AM',
            day = dayNames[today.getDay()];
        year = (""+year).slice(-2);
        month = ("0" + month).slice(-2);
        date = ("0" + date).slice(-2);
        hour = ("0" + hour).slice(-2);
        minute = ("0" + minute).slice(-2);
        second = ("0" + second).slice(-2);
        return `[${year}/${month}/${date} ${hour}:${minute}:${second}]`
    }

    function appendLog(item, op=0) {
        let doScroll = log.scrollTop > log.scrollHeight - log.clientHeight - 1;
        let curTime = getTime();
        lineCount += 1;
        let lineNum = "" + lineCount;
        for(let i = (lineCount+"").length; i < 5; i++) {
            lineNum = "&nbsp;" + lineNum
        }
        if (op == 0) {
            item.innerHTML = "<span style='color:#ababab'>" + lineNum + ":</span> <span style='color:#555'>" + curTime + "</span> " + item.innerHTML;
        }else {
            item.innerHTML = "<span style='color:#ababab'>" + lineNum + ":</span> <span style='color:orange'>" + curTime + item.innerHTML + "</span> ";
        }

        log.appendChild(item);
        if (doScroll) {
            log.scrollTop = log.scrollHeight - log.clientHeight;
        }
    }

    function clearLog() {
        while (log.firstChild) {
            log.removeChild(log.firstChild);
        }
        lineCount = 0;
    }

    document.getElementById("form").onsubmit = function () {
        let curMessage = msg.value;
        store.put(curMessage);
        msg.value = "";
        if (!curMessage) {
            return false;
        }
        switch (curMessage) {
            case 'clear':
                clearLog();
                return false;
            case 'connect':
                connectServer();
                break;
            case 'help':
                break;
            default:
                break;
        }
        if (!conn) {
            return false;
        }
        let item = document.createElement("div");
        if (conn.readyState === WebSocket.CLOSED) {
            item.innerHTML = "<b>ERR: Connection Closed.</b>";
        }else{
            item.innerHTML = "<i><- "+ curMessage+"</i>";
        }
        appendLog(item);
        conn.send(curMessage);
        return false;
    };

    var store = {
        keyCount:0,
        commandCount:0,
        prevCommand:[],
        put : function(val) {
            this.commandCount++;
            this.keyCount = this.commandCount;
            this.prevCommand.push(val);
        },
        get : function() {
            this.keyCount--;
            if(typeof this.prevCommand[this.keyCount] !== "undefined") {
                return this.prevCommand[this.keyCount];
            }
        }

    }


    $(document).keydown(function(event){
        if(event.which == 38 && $("#msg").is(":focus")){
             var val = store.get();
             if (typeof val !== "undefined"){
                 msg.focus();
                 msg.value = '';
                 msg.value = val;
             }
        }
    });

    connectServer();
};