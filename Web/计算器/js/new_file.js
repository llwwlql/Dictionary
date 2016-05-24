function compute()
{
	var Amount=document.getElementById("amount");
	var Rate=document.getElementById("rate");
	var Show1=document.getElementById("show");
	var Show2=document.getElementById("show-sum");
	var se=document.getElementById("year");
	Show1.value = Amount.value*Rate.value*0.01*se.value;
	Show2.value = parseInt(Show1.value) + parseInt(Amount.value);
}
function l_close()
{
	document.getElementById("rate").disabled=false;
}
function l_open()
{
	var se=document.getElementById("year");
	var Rate=document.getElementById("rate");
	document.getElementById("rate").disabled=true;
	if(se.value==0.5)
		Rate.value=1.35;
	else if(se.value==1)
		Rate.value=2.32;
	else if(se.value==3)
		Rate.value=3.43;	
	else
		Rate.value=4.21;
}
function l_year()
{
	var au=document.getElementById("auto");
	var Rate=document.getElementById("rate");
	var se=document.getElementById("year");
	if(au.checked==true)
	{
		if(se.value==0.5)
			Rate.value=1.35;
		else if(se.value==1)
			Rate.value=2.32;
		else if(se.value==3)
			Rate.value=3.43;	
		else
			Rate.value=4.21;
	}
}