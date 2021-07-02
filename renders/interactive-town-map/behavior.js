var zoomLevel = 0.5;
const baseWidth = 16384;
const baseHeight = 8192;
const lastMod = document.lastModified;
var textHid = false;

// object coordinates are in LDU
const objects =
{
	b001:[ -320, 0, 320],
	b002:[-2240, 0, 320]
}

function Convert_LDR2IMG(inLDR) {
	const ratioLDR2IMG = 256/640;
	const tempX1 = ratioLDR2IMG   * -inLDR[0];
	const tempY1 = ratioLDR2IMG/2 *  inLDR[0];
	const tempX2 = 0;
	const tempY2 = ratioLDR2IMG/Math.cos(Math.PI/4) * Math.cos(Math.PI/6) * inLDR[1];
	const tempX3 = ratioLDR2IMG   *  inLDR[2];
	const tempY3 = ratioLDR2IMG/2 *  inLDR[2];
	const outIMG = [tempX1 + tempX2 + tempX3 + baseWidth/2, tempY1 + tempY2 + tempY3 + baseHeight/2];
	return outIMG;
}
function Convert_IMG2WIN(inIMG) {
	const winWidth = document.documentElement.clientWidth || document.body.clientWidth;
	const winHeight = document.documentElement.clientHeight || document.body.clientHeight;
	const outWIN = [inIMG[0]*zoomLevel-winWidth/2, inIMG[1]*zoomLevel-winHeight/2];
	return outWIN;
}
function Convert_WIN2IMG(inWIN) {
	const winWidth = document.documentElement.clientWidth || document.body.clientWidth;
	const winHeight = document.documentElement.clientHeight || document.body.clientHeight;
	const outIMG = [(inWIN[0]+winWidth/2)/zoomLevel, (inWIN[1]+winHeight/2)/zoomLevel];
	return outIMG;
}
function Place_Popups() {
	const outIMG = Convert_LDR2IMG(objects.b002);
	document.querySelector('#b002p').style.left = outIMG[0]*zoomLevel-224-256*zoomLevel + 'px';
	document.querySelector('#b002p').style.top  = outIMG[1]*zoomLevel- 48 + 'px';
	document.querySelector('#b002m').style.left = outIMG[0]*zoomLevel + 'px';
	document.querySelector('#b002m').style.top  = outIMG[1]*zoomLevel + 'px';
}
function Toggle_Popup(inID) {
	const thisPostit = document.querySelector(inID);
	if (thisPostit.style.display == 'block')
		thisPostit.style.display = 'none';
	else
		thisPostit.style.display = 'block';
}
function Scroll_To_Middle() {
	const imgCooOut = Convert_LDR2IMG(objects.b001);
	Scroll_To_Target(imgCooOut);
}
function Scroll_To_Target(imgCooIn) {
	const winCooOut = Convert_IMG2WIN(imgCooIn);
	window.scroll(winCooOut[0], winCooOut[1]);
}
function Get_Current_Scroll() {
	const winCooIn = [window.pageXOffset, window.pageYOffset];
	const imgCooOut = Convert_WIN2IMG(winCooIn);
	return imgCooOut;
}
function Zoom_In() {
	const imgCoo = Get_Current_Scroll();
	zoomLevel *= 2;
	Zoom_Update();
	Scroll_To_Target(imgCoo);
}
function Zoom_Out() {
	const imgCoo = Get_Current_Scroll();
	zoomLevel /= 2;
	Zoom_Update();
	Scroll_To_Target(imgCoo);
}
function Zoom_Update() {
	document.querySelector('#embed').setAttribute('width', baseWidth * zoomLevel);
	document.querySelector('#embed').setAttribute('height', baseHeight * zoomLevel);
	if (zoomLevel >= 1)
		document.querySelector('#level').innerHTML = 'Zoom Level: ' + zoomLevel;
	else
		document.querySelector('#level').innerHTML = 'Zoom Level: 1/' + (1/zoomLevel);
	Place_Popups();
}
function Toggle_Text() {
	if (textHid == true) {
		document.querySelector('#float1').style.display = 'block';
		document.querySelector('#float2').style.display = 'block';
		textHid = false;
	}
	else {
		document.querySelector('#float1').style.display = 'none';
		document.querySelector('#float2').style.display = 'none';
		textHid = true;
	}
}
function init() {
	Zoom_Update();
	// doesn't fire in Chrome 80 unless there is a timeout before executing init()
	Scroll_To_Middle();
	// in firefox 72 the embedded PNG images are loaded noticeably after the SVG image is made visible instead of before
	document.querySelector('#embed').style.visibility = 'visible';
	document.querySelector('#cross').style.visibility = 'visible';
	document.querySelector('#load').style.visibility = 'hidden';
	document.querySelector('#lastmod').innerHTML = lastMod;
}
/*
document.onreadystatechange = function () {
	if (document.readyState == "complete") {
		setTimeout(init, 10);
	}
}
*/
window.onload = function () {
	setTimeout(init, 10);
}
