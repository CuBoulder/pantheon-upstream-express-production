<?php
/**
 * @file
 * Template for servicecloud include, previously named salesforcechat.
 */
?>
<style type='text/css'>
    .helpButton {
         width: 225px;
    }
    .embeddedServiceHelpButton .helpButton .uiButton {
        background-color: #005290;
        font-family: "Arial", sans-serif;
        min-width: fit-content;
    }
    .embeddedServiceHelpButton .helpButton .uiButton:focus {
        outline: 1px solid #005290;
    }
    .embeddedServiceHelpButton .uiButton .helpButtonLabel .message{
        overflow:initial;
        white-space: break-spaces;
    }
    .embeddedServiceSidebarMinimizedDefaultUI .minimizedText>.message{
        overflow:visible;
        white-space:break-spaces;
    }
      /* color */
    .embeddedServiceSidebarMinimizedDefaultUI .content{
        background-color: #CFB87C;
        color: #222;
    }
    .embeddedServiceSidebarMinimizedDefaultUI.helpButton{
        background-color: #CFB87C;
        border-color: #CFB87C;
        padding: 0px;
    }
	.embeddedServiceHelpButton .helpButton .uiButton {
		background-color: #CFB87C;
        color: #111;
		font-family: "Arial", sans-serif;
        font-weight: bolder;
	}
	.embeddedServiceHelpButton .helpButton .uiButton:focus {
		outline: 1px solid #CFB87C;
	}
    .embeddedServiceHelpButton .helpButton .helpButtonEnabled:hover::before, .embeddedServiceHelpButton .helpButton .helpButtonEnabled:focus::before {
        opacity: 1;
        background-color: #a6a6a6;
    }
    .embeddedServiceSidebarButton .label, .embeddedServiceSidebarButton:disabled .label,
    .embeddedServiceSidebarButton .label:hover, .embeddedServiceSidebarButton:hover .label {
        color: #111;
    }
    .embeddedServiceSidebarButton:not(:disabled):focus, .embeddedServiceSidebarButton:not(:disabled):hover {
        background: #a6a6a6;
    }
   .embeddedServiceLiveAgentStateChatPlaintextMessageDefaultUI.chasitor.plaintextContent {
       color: #111;
    }

 @supports (-webkit-touch-callout: none) {
    .embeddedservice-chat-header lightning-icon, embeddedservice-chat-header svg.slds-icon-text-default{
        fill: rgb(255, 255, 255) !important;
    }

    .slds-icon-text-default{
        visibility:hidden;
    }
    .embeddedservice-chat-header lightning-icon, embeddedservice-chat-header svg.slds-icon-text-default{
        margin-bottom:-20px;
    }
    .slds-icon-utility-close:after{
        content: "X";
        color:black;
        font-size:medium;
    }

    /* @mediascreen button, input[type="reset"], input[type="submit"], input[type="button"]{
        font-size: 25%;
    } */
    .slds-icon-utility-minimize-window:after {
        content: "__";
        color:black;
        font-size:medium;
    }
    button.closeButton[embeddedService-chatHeader_chatHeader]{
        padding-top:0px;
    }
    .closeButton{
        margin-top:-13px;
        font-size:revert;
        font-weight:bolder;
    }
    .minimizeButton{
        margin-top:-13px;
        font-size:revert;
        font-weight:bolder;
    }
}
</style>

<script type='text/javascript' src='https://service.force.com/embeddedservice/5.0/esw.min.js'></script>
<script id="service-cloud-chat" type='text/javascript'>
    const enableAutoOpen = <?php print check_plain($enable_auto_open); ?>;
    const autoOpenTime = <?php print check_plain($auto_open_time); ?>;
    const enableEyeCatcher = <?php print check_plain($enable_eye_catcher); ?>;

    // Auto Open and Eye Catcher should be enabled only on desktop browsers.
    if(!(/Android|webOS|iPhone|iPad|iPod|mobile.+firefox|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent))) {
        if (enableAutoOpen === 1) {
            embedded_svc.addEventHandler("onSettingsCallCompleted", function(data) {
                document.querySelector(".embeddedServiceHelpButton").addEventListener('click', closeEyeCatcher);
                setTimeout(
                    function() {
                        closeEyeCatcherAndBootstrap();
                    },
                    autoOpenTime * 1000
                );
            });
        }

        if (enableEyeCatcher === 1) {
            addEyeCatcherHtml();
        }
    }

    var initESW = function(gslbBaseURL) {
        embedded_svc.settings.displayHelpButton = true; //Or false
        embedded_svc.settings.language = ''; //For example, enter 'en' or 'en-US'
        embedded_svc.settings.defaultMinimizedText = 'Questions? Let\'s Chat'; //(Defaults to Chat with an Expert)
        embedded_svc.settings.disabledMinimizedText = 'Liaison Unavailable'; //(Defaults to Agent Offline)
        embedded_svc.settings.offlineSupportMinimizedText = 'Questions? Let\'s Chat'; //(Defaults to Contact Us)
        embedded_svc.settings.enabledFeatures = ['LiveAgent'];
        embedded_svc.settings.entryFeature = 'LiveAgent';

        embedded_svc.init(
			'https://cu.my.salesforce.com',
			'https://cu.my.salesforce-sites.com/BuffInfo',
			gslbBaseURL,
			'00Do0000000Gz4V',
			'Buff_Info_Chat_Team',
			{
				baseLiveAgentContentURL: 'https://c.la3-c1-ia7.salesforceliveagent.com/content',
				deploymentId: '5722T0000008OsB',
				buttonId: '5732T000000Cb3s',
				baseLiveAgentURL: 'https://d.la3-c1-ia7.salesforceliveagent.com/chat',
				eswLiveAgentDevName: 'EmbeddedServiceLiveAgent_Parent04I2T000000005EUAQ_18603851c77',
				isOfflineSupportEnabled: true
            }
        );

        const status = data.isAgentAvailable ? "online": "offline";
        console.log(`onSettingsCallCompleted event was fired. Agent availability status is ${status}.`);
    };

    if (!window.embedded_svc) {
		var s = document.createElement('script');
		s.setAttribute('src', 'https://cu.my.salesforce.com/embeddedservice/5.0/esw.min.js');
		s.onload = function() {
			initESW(null);
		};
		document.body.appendChild(s);
	} else {
		initESW('https://service.force.com');
    }

    function closeimg() {
        const img = document.querySelector("#eye-catcher");
        if (img != null) {
            img.style.display = "none";
        }
    }

    function closeEyeCatcherAndBootstrap() {
        closeimg();
        embedded_svc.bootstrapEmbeddedService();
    }

    function addEyeCatcherHtml() {
        const eyeCatcher = document.createElement("div");
        const eyeCatcherCloser = document.createElement("div");
        const eyeCatcherImgDiv = document.createElement("div");
        const eyeCatcherImg = document.createElement("img");

        eyeCatcher.id = "eye-catcher";
        eyeCatcher.style = "position: fixed; visibility: visible; z-index: 2147483639; background: transparent; border: 0px; padding: 10px 10px 0px 0px; float: left; margin-right: -10px; backface-visibility: hidden; bottom: 59px; right: 13px;"

        eyeCatcherCloser.style = "position: absolute; display: block; top: -5px; right: -3px; width: 16px; line-height: 16px; text-align: center; cursor: pointer; text-decoration: none; color: rgb(0, 0, 0); font-size: 20px; font-family: Arial, sans-serif; border-radius: 50%; background-color: rgba(255, 255, 255, 0.5);";
        eyeCatcherCloser.addEventListener("click", closeimg);
        eyeCatcherCloser.textContent = "x";

        eyeCatcherImgDiv.id = "eye-catcher-img";
        eyeCatcherImgDiv.style = "display: block; overflow: hidden; cursor: pointer;"

        eyeCatcherImg.id = "imagID";
        eyeCatcherImg.alt = "Chat now";
        eyeCatcherImg.addEventListener("click", closeEyeCatcherAndBootstrap);
        eyeCatcherImg.src = "https://cdn.livechat-files.com/api/file/lc/main/12416433/0/ec/3cd23a1c1292c884141874e90a228a2b.png";
        eyeCatcherImg.style = "display: block; border: 0px; float: right; width: 275px; height: 124px;"

        eyeCatcher.appendChild(eyeCatcherCloser);
        eyeCatcherImgDiv.appendChild(eyeCatcherImg);
        eyeCatcher.appendChild(eyeCatcherImgDiv);

        const chatScript = document.querySelector("#service-cloud-chat");
        chatScript.after(eyeCatcher);
    }
</script>
