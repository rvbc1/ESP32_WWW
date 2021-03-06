const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
body {
	background-color:gray;
}
.page{
	 width:100%
}
.card_container{
	 display: table;
	 margin: 0 auto;
}

.card{
     display:inline-block;
     min-height: 250px;
     background: #02b875;
     padding: 30px;
     box-sizing: border-box;
     color: #FFF;
	 margin: 20px;
     box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
</style>
<body>
<div class="page">
<div class="card_container">
<div class="card">
  <h1>Selfie_ESP32 web interface</h1><br>
  <h2>Timestamp: <span id="time">0</span></h2><br>
  <h2>BT: <span id="BT_DATA">no data</span></h2><br>
  <h2>Available WiFi: <span id="WiFi_networks">no data</span></h2><br>
</div>
</div>
</div>
<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
  getBT();
  getWifi();
}, 1000); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("time").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readTime", true);
  xhttp.send();
}

function getBT() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("BT_DATA").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readBT", true);
  xhttp.send();
}


function getWifi() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("WiFi_networks").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readWifi", true);
  xhttp.send();
}

</script>
</body>
</html>
)=====";