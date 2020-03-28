#include <ESP8266WiFi.h>

const char index_html[] PROGMEM = R"=====(<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
    <style>
      html,
      body {
        height: 90%;
      }
      #tittle {
        height: 60px;
        width: 100%;
        background-color: rgb(10, 23, 70);
        color: aliceblue;
        font-size: 36px;
        font-weight: bolder;
        line-height: 60px;
        text-align: center;
      }
      #out {
        display: flex;
        justify-content: space-between;
        text-align: center;
        height: 100%;
        padding: 10% 5%;
        box-sizing: border-box;
      }
      #middle {
        height: 100%;
        display: flex;
        justify-content: center;
        flex-direction: column;
        align-items: center;
        margin: 0 30px;
      }
      #second {
        height: 50px;
        width: 100%;
        display: flex;
        justify-content: space-around;
        flex-direction: row;
        align-items: center;
        margin: 20px 0;
      }
      .arround {
        height: 100%;
        display: flex;
        flex-direction: column;
        justify-content: space-between;
      }
      .arround > div {
        height: 40px;
        width: 200px;
        line-height: 40px;
        background-color: cornflowerblue;
        color: aliceblue;
        font-size: 22px;
      }
      #circle {
        height: 50px;
        width: 50px;
        border-radius: 50px;
        background-color: red;
        margin: 0;
        position: relative;
        margin: 0 20px;
      }
      #triTop,
      #triDown {
        height: 100px;
        width: 40px;
        background-color: cornflowerblue;
      }
      #triLeft,
      #triRight {
        height: 40px;
        width: 100px;
        background-color: cornflowerblue;
      }
      #triTop::before {
        content: "";
        position: relative;
        left: -50%;
        top: -50%;
        width: 0px;
        height: 0px;
        border-bottom: 30px solid cornflowerblue;
        border-right: 40px solid transparent;
        border-left: 40px solid transparent;
      }
      #triDown::after {
        content: "";
        position: relative;
        left: -50%;
        top: 120px;
        width: 0px;
        height: 0px;
        border-top: 30px solid cornflowerblue;
        border-right: 40px solid transparent;
        border-left: 40px solid transparent;
      }
      #triLeft::before {
        display: block;
        content: "";
        position: relative;
        transform: translateX(-100%);
        top: -50%;
        width: 0px;
        height: 0px;
        border-bottom: 40px solid transparent;
        border-top: 40px solid transparent;
        border-right: 30px solid cornflowerblue;
      }
      #triRight::after {
        display: block;
        content: "";
        position: relative;
        left: 100%;
        top: -50%;
        width: 0px;
        height: 0px;
        border-bottom: 40px solid transparent;
        border-top: 40px solid transparent;
        border-left: 30px solid cornflowerblue;
      }
      #block {
        height: 15px;
        width: 100%;
        background-color: rgb(10, 23, 70);

        line-height: 15px;
      }
      #finale {
        text-align: center;
        font-size: 18px;
      }
    </style>
    <script src="https://cdn.bootcss.com/axios/0.19.0-beta.1/axios.min.js"></script>
    <script>
      function quest(item) {
        axios
          .get(`/move?dir=${item}`)
          .then(function(response) {
            console.log(response.data);
          })
          .catch(function(err) {
            console.log(err);
          });
      }
    </script>
  </head>
  <body>
  <div id="tittle">WAM-USV</div>
    <div id="out">
      <div id="left" class="arround">
        <div class="top" onclick="quest('z')">
          Zigzag
        </div>
        <div class="down" onclick="quest('r')">
          Random
        </div>
      </div>
      <div id="middle">
        <div id="triTop" onclick="quest('U')"></div>
        <div id="second">
          <div id="triLeft" onclick="quest('L')"></div>
          <div id="circle" onclick="quest('S')"></div>
          <div id="triRight" onclick="quest('R')"></div>
        </div>
        <div id="triDown" onclick="quest('D')">
          <div class="tribor"></div>
        </div>
      </div>
      <div id="right" class="arround">
        <div class="top" onclick="quest('c')">
          Turning circle
        </div>
        <div class="down" onclick="quest('h')">
          Scheduled
        </div>
      </div>
    </div>
    <div id="block"></div>
    <div id="finale">
      Institute of Marine Science and Technology, Shandong University
    </div>
  </body>
</html>
)=====";
