@NewsletterBundle
Feature: Newsletter Node Type
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a newsletter

Scenario Outline: An authenticated user should be able to access the form for adding a newsletter
Given I am logged in as a user with the <role> role
When I go to "node/add/newsletter"
Then I should see <message>

Examples:
 | role            | message             |
 | edit_my_content | "Access Denied"     |
 | edit_only       | "Access Denied"     |
 | site_editor     | "Create Newsletter" |
 | site_owner      | "Create Newsletter" |
 | administrator   | "Create Newsletter" |
 | developer       | "Create Newsletter" |

Scenario: An anonymous user should not be able to access the form for adding a newsletter
When I am on "node/add/newsletter"
Then I should see "Access denied"
